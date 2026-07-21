import java.util.Scanner;

class Main {

    public int foo(int K, int N, int[] dist) {
        int last = K;
        int max = 0;
        for (int i = 1; i < N; i++) {
            int d = dist[i]-dist[i-1];
            max = Math.max(max, d);
            last -= d;
        }
        max = Math.max(max, last);
        return K - max;
    }

	public static void main(String[] args){
        Main o = new Main();

		Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        // sc.close();

        System.out.println(o.foo(K, N, arr));
	}
}
