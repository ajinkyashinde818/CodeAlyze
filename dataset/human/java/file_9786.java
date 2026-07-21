import java.io.*;
import java.util.*;

public class Main {
        public static void main(String[] args) {
                Scanner scan = new Scanner(System.in);

                int N = scan.nextInt();
                int M = scan.nextInt();
                int X = scan.nextInt();

                int[] C = new int[N];

                int[][] A = new int[N][M];

                for (int gyou = 0; gyou < N; gyou++) {
                        C[gyou] = scan.nextInt();
                        for (int retsu = 0; retsu < M; retsu++) {
                               A[gyou][retsu] = scan.nextInt(); 
                        }
                }

                int min = 0;
                int first_flag = 1;

                for (int bit = 0; bit < Math.pow(2,N); bit++) {
                        int kingaku = 0;
                        int[] rikaido = new int[M];

                        for (int sft = 0; sft < N; sft++) {
                                if ((1&bit>>sft) == 1) {
                                        kingaku += C[sft];
                                        for (int rikaido_res = 0; rikaido_res < M; rikaido_res++) {
                                                rikaido[rikaido_res] += A[sft][rikaido_res];
                                        }
                                }
                        }

                        int tassei_count = 0;
                        for (int tassei_res = 0; tassei_res < M; tassei_res++) {
                                if (rikaido[tassei_res] >= X) {
                                        tassei_count++;
                                }
                        }

                        if ((tassei_count == M && min > kingaku) || (first_flag == 1 && tassei_count == M)) {
                                min = kingaku;
                                first_flag = 0;
                        }
                }

                if (min == 0) {
                        System.out.println(-1);
                } else {
                        System.out.println(min);
                }
        }
}
