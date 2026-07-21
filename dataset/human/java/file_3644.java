import java.util.Scanner;
public class Main {
    public static void main(String[] args){
    
    Scanner sc = new Scanner(System.in);
    String X = sc.next();
    char[]x = X.toCharArray();
    String Y = sc.next();
    char[]y = Y.toCharArray();
    
    if(x[0]+0 > y[0]+0) {
    	System.out.println(">");
    }else if(x[0]+0 < y[0]+0) {
   	 	System.out.println("<");
    }else {
    	System.out.println("=");
    }
}
    }
