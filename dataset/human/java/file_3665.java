import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		//String tmp = sc.next();
		//int tmp = sc.nextInt();
		//Long tmp = sc.nextLong();
      String X = sc.next();
      String Y = sc.next();
      String list = "ABCDEF";
      if(list.indexOf(X) < list.indexOf(Y)){
        System.out.println("<");
      }else if(list.indexOf(X) > list.indexOf(Y)){
        System.out.println(">");
      }else{
        System.out.println("=");
      }
	}
}
