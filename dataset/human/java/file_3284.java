import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String n = sc.next();
        if(n.substring(0,1).equals("9")) {
            System.out.println("Yes");
        } else if (n.substring(1,2).equals("9")) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
