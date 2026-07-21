import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] n = sc.next().split("");

        boolean ans = false;
        for (int i = 0; i < n.length; i++) {
            if (n[i].equals("9")) ans = true;
        }

        if (ans) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
