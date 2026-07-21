import javax.print.DocFlavor;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.function.BiConsumer;
import java.util.stream.Collectors;

public class Main {

    //グローバル変数を定義

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    void run() {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextInt();
        long b = sc.nextInt();
        long c = sc.nextInt();
        long ans = 0;

        long gedo = a+b;

        if(gedo == 0) {
            if(c != 0) {
                ans = 1;
            }
        } else {
            if (gedo >= c) {
                ans = b + c;
            } else {
                ans = gedo + b + 1;
            }
        }

        System.out.println(ans);
    }

    double calcTemp(int t, int h) {
        return t - h * 0.006;
    }
}
//
//class Combination1 {
//    // 候補となるリストと、何個ピックアップするかを渡す
//    public static List<List<Integer>> make (List<Integer> candidate, int r) {
//        // 5C6みたいなのは空
//        // 0C5も空
//        // 5C0も空
//        if (candidate.size() < r || candidate.size() <= 0 || r <= 0) {
//            List<List<Integer>> empty = new ArrayList<>();
//            empty.add(new ArrayList<>());
//            return empty;
//        }
//
//        List<List<Integer>> combination = new ArrayList<>();
//        // 5C3だったら、添字0, 1, 2だけ考えたらいい
//        for (int i = 0; i <= candidate.size() - r; i++) {
//            // 一つ取り出して
//            Integer picked = candidate.get(i);
//            List<Integer> rest = new ArrayList<>(candidate);
//            // 以降の文字を削って
//            rest.subList(0, i + 1).clear();
//            // 再帰呼び出しし、得られたリストの全ての先頭に取り出したものを結合する
//            combination.addAll(make(rest, r - 1).stream().map(list -> {
//                list.add(0, picked);
//                return list;
//            }).collect(Collectors.toList()));
//        }
//        return combination;
//    }
//}

//
//class Gauss {
//    //連立方程式の係数
//    //a[N][N](係数行列)とb[1](定数)を一緒にしたもの
//    double a[][];
//    int N;
//
//    Gauss(double[][] a, int N){
//        a = a;
//        N = N;
//    }
////    double a[][]={{1.0,1.0,1.0,1.0,10,0},
////            {2.0,1.0,3.0,2.0,21.0},
////            {1.0,3.0,2.0,1.0,17.0},
////            {3.0,2.0,1.0,1.0,14.0}};
////    int N=a.length;
//
//    //Gaussの消去法で連立方程式を解く
//    void gauss(){
//        //前進消去
//        double s;
//        for(int k=0; k<N-1; k++){
//            for(int i=k+1; i<N; i++){
//                s=a[i][k]/a[k][k];
//                for(int j=k+1; j<=N; j++){
//                    a[i][j] -= s * a[k][j];
//                }
//            }
//        }
//        //後退代入
//        for(int i=N-1; i>=0; i--){
//            s=a[i][N];
//            for(int j=i+1; j<N; j++){
//                s -= a[i][j] * a[j][N];
//            }
//            a[i][N] = s/a[i][i];
//        }
//    }
//    public static void run() {
//        Gauss gs= new Gauss();
//        gs.gauss();
//        //解の表示
//        System.out.println("ガウスの消去法による連立1次方程式の解");
//        for(int i=0; i<gs.N; i++){
//            System.out.println("x["+i+"] = "+gs.a[i][gs.N]);
//        }
//    }
//}
