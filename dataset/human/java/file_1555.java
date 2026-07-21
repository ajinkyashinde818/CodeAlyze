import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        int[][] board = new int[N][N];
        int[][] temp = new int[M][M];

        for(int i = 0; i<N; i++) {
            String str = sc.next();
            for(int j = 0; j<N; j++) {
                board[i][j] = (str.charAt(j)=='#')?1:0;
            }
        }

        for(int i = 0; i<M; i++) {
            String str = sc.next();
            for(int j = 0; j<M; j++) {
                temp[i][j] = (str.charAt(j)=='#')?1:0;
            }
        }

        boolean f = false;
        for(int i = 0; i<=N-M; i++) {
            for(int j = 0; j<=N-M; j++) {
                f = true;
                for(int ii = 0; ii<M; ii++) {
                    for(int jj = 0; jj<M; jj++) {
                        if(board[i+ii][j+jj] != temp[ii][jj]) {
                            f=false;
                            //System.out.println(f);
                        }
                        //System.out.println(i+" "+j+" "+board[i+ii][j+jj] +" "+ temp[ii][jj]);
                    }
                }
                //System.out.println("f = " + f);
                if(f) {
                    System.out.println("Yes");
                    return;
                }
            }

        }

        System.out.println("No");

    }
}
