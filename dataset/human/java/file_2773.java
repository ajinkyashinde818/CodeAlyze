import java.util.*;
 
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        char[] cs = s.toCharArray();
        char[] ct = t.toCharArray();
        Arrays.sort(cs);
        Arrays.sort(ct);
        String ss = new String(cs);
        String st = new String(ct);
        st = new StringBuilder(st).reverse().toString();
        if(ss.compareTo(st) < 0){
        	System.out.println("Yes");
        }else{
        	System.out.println("No");
        }
	}
}
