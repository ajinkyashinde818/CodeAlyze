import java.util.*;
public class Main{
    static Scanner kbd = new Scanner(System.in);
    public static void main(String[] args){
	while(kbd.hasNext()){
	    int n = kbd.nextInt();
	    if(n!=0) solve(n);
	}
    }

    static void solve(int n){
	int[] key = new int[n];
	String[] ss = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", 
		       "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v",
		       "w", "x", "y", "z", "A", "B", "C", "D", "E", "F", "G",
		       "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R",
		       "S", "T", "U", "V", "W", "X", "Y", "Z"};
	int i, j, k;
	// 鍵読み込み
	for(i=0; i<n; i++){
	    key[i] = kbd.nextInt();
	}
	String s = kbd.next(); // リスト
	//System.out.println(s);
	String ans = "";
	i=0;
	k=0;
	while(i<s.length()){
	    String x = s.substring(i, i+1);
	    j=0;
	    while(!x.equals(ss[j])) j++;
	    //System.out.println(k);
	    ans += ss[(j-key[k]+ss.length)%ss.length];
	    i++;
	    k = (k+1)%n;
	}
	System.out.println(ans);
    }
}
