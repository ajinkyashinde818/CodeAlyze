import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int max = 0;
        int pre = -1;
        int first = 0;
        int last = 0;
        for (int i = 0; i < N; i++) {
            int data = sc.nextInt();
            if (pre == -1) {
                first = data;
            } else {
                int dist = data - pre;
                if (dist > max)
                    max = dist;
            }
            if (i == N - 1)
                last = data;
            pre = data;
        }
        if (K - last + first > max)
            max = K - last + first;
        System.out.println(K - max);

    }
}
