import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        boolean flagA = false;
        boolean flagB = false;
        boolean flagC = false;
        for (int i = 0; i < 3; i++) {
            if (str.charAt(i) == 'a') {
                flagA = true;
            }
            if (str.charAt(i) == 'b') {
                flagB = true;
            }
            if (str.charAt(i) == 'c') {
                flagC = true;
            }
        }
        String ans;
        if (flagA && flagB && flagC) {
            ans = "Yes";
        } else {
            ans = "No";
        }
        System.out.println(ans);

    }
}
