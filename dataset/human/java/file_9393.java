import java.util.Scanner;

public class Main {

    public static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int cnt = 0;
        boolean isZ = false;
        for (int i = 0; i < n; i++) {
            int d1 = Integer.parseInt(sc.next());
            int d2 = Integer.parseInt(sc.next());
            if (d1 == d2) {
                cnt++;
                if (cnt == 3) {
                    isZ = true;
                }
            } else {
                cnt = 0;
            }
        }
        if (isZ) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
