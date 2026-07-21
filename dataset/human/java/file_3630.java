import java.util.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();

        char c = a.charAt(0);
        char d = b.charAt(0);
        if(c > d){
            System.out.println(">");
        }
        else if (c < d){
            System.out.println("<");
        }
        else {
            System.out.println("=");
        }
    }
}
