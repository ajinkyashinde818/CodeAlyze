import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        // 整数の入力
        int N = sc.nextInt();
        int[] A = new int[N];
        int[] B = new int[50];
        int[] C = new int[50];
        for(int i=0;i<N;i++){
            A[i] = sc.nextInt()-1;
        }
        for(int i=0;i<N;i++){
            B[i] = sc.nextInt();
        }
        for(int i=0;i<N-1;i++){
            C[i] = sc.nextInt();
        }
        int manzoku=0;
        int bef = A[0];
        manzoku += B[A[0]];
        for(int i=1;i<N;i++){
            //eat A[i];
            int eat = A[i];
            manzoku += B[eat];
            if(eat ==  bef+1){
                manzoku += C[bef];
            }
            bef = eat;
        }
        System.out.println(manzoku);
    }
}
