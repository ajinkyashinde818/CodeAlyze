import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int K = scan.nextInt(), S = scan.nextInt();
        int x, y, cnt = 0;

        for (x=0; x <= K; x++) {
            int ylim = K;
            if (S-x < ylim) ylim = S-x;

            for (y=0; y <= ylim; y++) {
                if (S - x - y <= K) cnt++;
            }
        }

        System.out.println(cnt);
    }
}
