import java.util.Scanner;

/**
 * C - Traveling Salesman around Lake
 * 1 周 K メートルの円形の湖があり、その周りに N 軒の家があります。
 * i 番目の家は、湖の北端から時計回りに Ai メートルの位置にあります。
 * 家の間の移動は、湖の周りに沿ってのみ行えます。
 * いずれかの家から出発して N 軒すべての家を訪ねるための最短移動距離を求めてください。
 */
public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner( System.in );
        // 湖の円周の長さ
        int k = sc.nextInt();
        // 周りの家の数
        int n = sc.nextInt();
        // 家の間のそれぞれの距離
        int[] a = new int[n];
        for( int i = 0; i < n; i++ ) {
            a[i] = sc.nextInt();
        }

        int max = k - a[a.length - 1];
        int result = 0;
        for( int i = 1; i < n; i++ ) {
//            System.out.println("a["+ i +"]:" +a[i]);
//            System.out.println("a["+ (i-1) +"]:" +a[i -1]);
            result += a[i] - a[i - 1];
            if( max < a[i] - a[i - 1] ) {
                max = a[i] - a[i - 1];
            }
        }

        System.out.println( result > k - max ?  k - max : result );

        sc.close();
    }
}
