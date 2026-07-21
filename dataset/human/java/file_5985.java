import java.util.*;
public class Main{
	public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
      String str = sc.next();
      String p = str.substring(0,1);
      String q = str.substring(1,2);
      String r = str.substring(2,3);
      if(p.equals(q)||q.equals(r)||r.equals(p)) 
        System.out.println("No");
      else System.out.println("Yes");
      sc.close();
    }
}
