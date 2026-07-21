import java.util.Map;
import java.util.Scanner;
public class Main {


    public static void main(String[] args) {
int P=-1;

        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int M = scan.nextInt();
        int X = scan.nextInt();
        int C[] = new int[N];


        int A[][] = new int[N][M];
        for (int i = 0; i < N; i++) {
            C[i] = scan.nextInt();
            for (int ii = 0; ii < M; ii++) {
                A[i][ii] = scan.nextInt();
            }
        }
//入力完了


            for (int iii = 0; iii < (1 << N); iii++) {
                int PP=0;
                int S[] = new int[M];
                for (int j = 0; j < N; j++) {

                    if ((1 & iii >> j) == 1) {
                        for(int y=0;y<M;y++){S[y]=S[y]+A[j][y];}
                        PP=PP+C[j];
                    }

                }
                int K=0;
             for(int p=0;p<M;p++) {if(S[p]>=X){K=K+1;}  }
             if (K==M&&(P==-1||P>=PP)){P=PP;}
            }

        System.out.println(P);
    }

}
