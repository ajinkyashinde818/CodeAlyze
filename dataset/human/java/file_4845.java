import java.util.*;

class Main {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();

        if (N % 2 == 0) {
            if (N < 10) {
                System.out.println(0);
                System.exit(0);
            }

            long ans = 0;
            long div = 10;
            while (div <= N) {
                ans += (N/div);
                div *= 5;
            }

            System.out.println(ans);
        } else {
            System.out.println(0);
        }

    }
}
