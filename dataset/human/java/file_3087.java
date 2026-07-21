import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        new Main().compute();
    }

    void compute() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        boolean[] hop = new boolean[N];
        boolean[] step = new boolean[N];
        for (int i = 0; i < M; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (a == 1) {
                hop[b - 1] = true;
            } else if (b == 1) {
                hop[a - 1] = true;
            } else if (a == N) {
                step[b - 1] = true;
            } else if (b == N) {
                step[a - 1] = true;
            }
        }
        for (int i = 0; i < N; i++) {
            if (hop[i] && step[i]) {
                System.out.println("POSSIBLE");
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
