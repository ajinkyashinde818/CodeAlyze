import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int X = sc.nextInt();

        int[] price = new int[N];
        int[][] grow = new int[N][M];
        for(int i = 0; i < N; i++) {
            price[i] = sc.nextInt();
            for(int j = 0; j < M; j++) {
                int tmp = sc.nextInt();
                grow[i][j] = tmp;
            }
        }
        int min = Integer.MAX_VALUE;
        for(int bit = 0; bit < (1<<N); bit++) {
            int[] total = new int[M];
            int tmpMin = 0;
            for(int i = 0; i < N; i++) {
                if(((bit >> i) & 1) == 1) {
                    tmpMin += price[i];
                    for(int j = 0; j < M; j++) {
                        total[j] += grow[i][j];
                        int t = 0;
                    }
                }
            }
            for(int k = 0; k < M; k++) {
                if(total[k] < X) break;
                if(k == M-1) {
                    min = Math.min(min, tmpMin);
                }
            }
        }
        if(min == Integer.MAX_VALUE) {
            System.out.println("-1");
        } else {
            System.out.println(min);
        }
    }
}
