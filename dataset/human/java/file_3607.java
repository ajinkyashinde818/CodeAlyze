import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        char x = a.charAt(0);
        char y = b.charAt(0);
        if(x > y) System.out.println(">");
        else if(x < y) System.out.println("<");
        else System.out.println("=");
    }
}
