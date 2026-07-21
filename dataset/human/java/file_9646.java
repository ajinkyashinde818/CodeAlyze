import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int a  = sc.nextInt();
            int b  = sc.nextInt();

            if (a == b) {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt > 2) {
                System.out.println("Yes");
                return;
            }
        }

        System.out.println("No");

        sc.close();

        }

    }
