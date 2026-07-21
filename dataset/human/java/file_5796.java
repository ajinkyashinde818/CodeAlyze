import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        if (s.equals("abc") ||s.equals("cba") || s.equals("acb") || s.equals("bac") || s.equals("bca") || s.equals("cab")) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

    }

}
