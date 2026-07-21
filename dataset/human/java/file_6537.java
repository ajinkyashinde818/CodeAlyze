import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int K = scan.nextInt();
    	int S = scan.nextInt();
        int a;
    	int b;
        int cnt = 0;

        for (a = 0; a <= K; a++) {
            int qw = K;
            if (S - a < qw) {
            	qw = S-a;
            	}for (b = 0; b <= qw; b++) {
                if (S - a - b <= K) cnt++;
            }
        }

        System.out.println(cnt);
    }
}
