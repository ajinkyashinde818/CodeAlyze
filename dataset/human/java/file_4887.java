import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
 

//result = Math.pow(num1, num3)
//StringBuffer str = new StringBuffer(hoge1);
//String hoge2 = str.reverse().toString();
//map.containsKey(A)

//Map<String, Integer> map = new HashMap<String, Integer>(n);
/*for ( キーのデータ型 key : マップの名前.keySet() ) {
	データのデータ型 data = マップの名前.get( key );
	
	// keyやdataを使った処理;
}*/

//ArrayList<String> cc = new ArrayList<>(n);
//Collections.sort(list);
//Array.sort(list);
//Arrays.asList(c).contains("a")
//list.set(1,"walk");
public class Main {
	private static Scanner sc = new Scanner(System.in);
	static void p(String ans) {System.out.println(ans);};
	static void p(int ans) {System.out.println(ans);};
	static void p(long ans) {System.out.println(ans);};
	static void p(double ans) {System.out.println(ans);};
	//static String eikomoji[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	static long N;
	public static void main(String[] args) {
		long v=sc.nextLong();
		long ans=0;
		
		if(v%2==1) {
			p(0);
		}else {
			long f=2;
			for(int i=1;true;i++) {
				f*=5;
				long g=(v/f);
				if(g<1) {
					break;
				}
				ans+=g;
			}
			p(ans);
		}
		
		
	}
	static int memo[]=new int[100000];
	static int dfs(int i) {
		if(memo[i]!=0) {
			return memo[i];
		}
		if(i<=1) {
			memo[i]=1;
			return 1;
		}
		memo[i]=i*dfs(i-2);
		return memo[i];
	}
	
	
	
}
