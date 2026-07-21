import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        if (n >= 10) {
            System.out.println(r);
            return;
        } else {
            System.out.println(r + (100 * (10 - n)));
            return;
        }
    }
}
