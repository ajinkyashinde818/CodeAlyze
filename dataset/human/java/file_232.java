import java.util.*;
import static java.lang.Math.abs;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); //配列の要素数
        int[] A = new int[N]; //入力された値の配列
        int[] B = new int[N]; //上記の配列の絶対値をとった配列
        boolean jud = true;
        int w = 0;
        long ans = 0;         //答え
        //入力
        for(int i = 0;i < N;i++){
            A[i] = sc.nextInt();
            B[i] = abs(A[i]);
        }

        Arrays.sort(A);
        Arrays.sort(B);

        //絶対値の一番小さい値と配列の一番後ろを交換
        while(jud == true){
            if(B[0] == A[w]){
                A[w] = A[N-1];
                A[N-1] = B[0];
                jud = false;
            }else if(B[0] == A[w]*(-1)){
                A[w] = A[N-1];
                A[N-1] = B[0] *(-1);
                jud = false;
            }
            w++;
        }

        //負の値を見つけ-1を乗算
        for(int i = 0;i < N-1;i++){
            if(A[i] < 0){
                A[i] = A[i] * (-1);
                A[i+1] = A[i+1] * (-1);
            }
        }

        //配列の和を計算
        for(int i = 0;i < N;i++){
            ans += A[i];
        }
        //出力
        System.out.println(ans);
    }
}
