import java.util.Scanner;
import java.io.PrintWriter;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int N = Integer.parseInt(sc.next());

        int[] A = new int[N]; //Aを配列で受け取る
        for (int i = 0; i < N; i++ ){
            A[i] = Integer.parseInt(sc.next()) - 1; //0-indexedにしたいのであらかじめ1引いておく
        }
        int B[] = new int[N]; //Bを配列で受け取る
        for (int i= 0; i < N; i++){
            B[i] = Integer.parseInt(sc.next());
        }
        int C[] = new int[N-1]; //Cを配列で受け取る
        for (int i=0; i<N-1; i++){
            C[i] = Integer.parseInt(sc.next());
        }

        int point = B[A[0]]; //最初の1食目はその料理の満足度のみ加算される
        for (int i = 1; i < N; i++){
            point += B[A[i]]; //料理を食べたときの満足度Biを足す
            if (A[i] == A[i-1] + 1){ //もし1個前の料理の番号が今回の料理の番号-1ならCiを足す
                point += C[A[i-1]];
            }
        }
        out.println(point);

        //テンプレ
        sc.close();
        out.flush();
    }
}
