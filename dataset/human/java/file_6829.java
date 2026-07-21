import java.util.Scanner;

// 12
class Main{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] a = new int[N + 1];
        for(int i = 0; i < N; ++i)
            a[i] = sc.nextInt();
        a[N] = a[0] + K;

        int t = 0;
        for(int i = 0; i < N; i++)
            t = Math.max(t, a[i + 1] - a[i]);

        System.out.println(K - t);
    }

}
