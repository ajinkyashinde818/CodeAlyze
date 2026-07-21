import java.util.*;
public class Main {
    private static int N;
    private static int M;
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        int X = sc.nextInt();
        int[] C = new int[N];
        int[][] A = new int[N][M];
        for(int i=0;i<N;i++){
            C[i] = sc.nextInt();
            for(int j=0;j<M;j++){
                A[i][j] = sc.nextInt();
            }
        }
        int minP = Integer.MAX_VALUE;
        for(int key=0;key<Math.pow(2, N);key++){
            int price = decodePrice(key, C);
            if(decodeAndIsOverX(key, A, X)){
                minP = Math.min(minP, price);
            }
        }
        if(minP == Integer.MAX_VALUE){
            minP = -1;
        }
        System.out.println(minP);
    }
    private static int decodePrice(int key, int[] C){
        int res=0;
        for(int i=0;i<N;i++){
            if(((key >> i) & 0x01) == 1){
                res += C[i];
            }
        }
        return res;
    }

    private static boolean decodeAndIsOverX(int key, int[][] A, int X){
        int[] sumA = new int[M];
        for(int i=0;i<N;i++){
            if(((key >> i) & 0x01) == 1) {
                for (int j = 0; j < M; j++) {
                    sumA[j] += A[i][j];
                }
            }
        }
        for(int i=0;i<M;i++){
            if(sumA[i] < X){
                return false;
            }
        }
        return true;
    }
    private static void showArr(int[] a){
        for(int p:a){
            System.out.print(p);
        }
        System.out.println();
    }

}
