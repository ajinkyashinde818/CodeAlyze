import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
      	String a = sc.next();
        char A = a.charAt(0);
      	String b = sc.next();
        char B = b.charAt(0);
      
        if(A < B){
      	System.out.println("<");
        }else if(A > B){
      	System.out.println(">");
        }else if(A == B){
      	System.out.println("=");
        }
      
    }
}
