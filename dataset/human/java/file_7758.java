import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long K = sc.nextLong();
        int[] city = new int[N+1];
        for (int i = 1; i < N+1; i++) {
            city[i] = sc.nextInt();
        }
        int[] step = new int[N+1];
        int now = 1;
        int tmp = 0;
        step[1] = 1;
        int front = 0;
        int roop = 0;
        boolean roopIn = false;
        for (int i = 0; i < K; i++) {
            tmp = now;
            now = city[now];
            if (step[now] == 1 && !roopIn) {
                front = i+1;
                roopIn = true;
            } else if (step[now] == 2) {
                roop = i - front;
                break;
            } else {
                step[now]++;
            }
        }
        if (roop != 0) {
            long Kres = (K-front)%roop;
            for (int i = 0; i < (int) Kres; i++) {
                tmp = city[tmp];
            }
            System.out.println(tmp);
        } else {
            System.out.println(now);
        }
    }
}
