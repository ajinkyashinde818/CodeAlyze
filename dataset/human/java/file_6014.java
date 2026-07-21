import java.util.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        boolean a = false;
        boolean b = false;
        boolean c = false;
        for (int i = 0; i < 3; i++) {
            if (s.charAt(i) == 'a') {
                a = true;
            } else if (s.charAt(i) == 'b') {
                b = true;
            } else if (s.charAt(i) == 'c') {
                c = true;
            }
        }
        if (a && b && c) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
