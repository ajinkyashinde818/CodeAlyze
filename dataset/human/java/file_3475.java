import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
    	String s1 = sc.next();
        String s2 = sc.next();
        int n1 = (int)s1.charAt(0);
        int n2 = (int)s2.charAt(0);
        if(n1 > n2){
        	System.out.println(">");
        }else if(n1 < n2){
        	System.out.println("<");
        }else{
        	System.out.println("=");
        }
    }
}
