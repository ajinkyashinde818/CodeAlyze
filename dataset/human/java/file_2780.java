import java.util.*;
public class Main{
	public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
      String s = sc.next();
      String t = sc.next();
      char[] s1 = s.toCharArray();
      char[] t1 = t.toCharArray();
      Arrays.sort(s1);
      Arrays.sort(t1);
      String s2 = new String(s1);
      String t2 = new String(t1);
      String t3 = new StringBuilder(t2).reverse().toString();
      if(s2.compareTo(t3)<0){
      	System.out.println("Yes");
      }else{
      	System.out.println("No");
      }
    }
}
