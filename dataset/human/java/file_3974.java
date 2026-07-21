import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        new Main().run();
    }

    private void run() {
        Scanner scanner = new Scanner(System.in);
        int N  = scanner.nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        int[] C = new int[N];
        for(int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        for(int i = 0; i < N; i++) {
            B[i] = scanner.nextInt();
        }
        for(int i = 0; i < N-1; i++) {
            C[i] = scanner.nextInt();
        }
        int ans = 0;
        int prev = -2;
        for(int i = 0; i < N; i++) {
            int cur = A[i] - 1;
            ans += B[cur];
            if(prev + 1 ==  cur){
                ans += C[prev];
            }
            prev = cur;
        }


        System.out.println(ans);
    }
}
