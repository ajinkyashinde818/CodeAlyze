import java.util.Scanner;

/**
 * B - Buffet
 * 料理は全部食べるので、満足度は最終的に全て足すことになる。
 *
 */
public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner( System.in );
        // ビュッフェでの料理の種類数
        int n = sc.nextInt();
//        System.out.println( "n : " + n );

        // 食べた順番
        int[] a = new int[n];
//        int addCount = 0;
        for( int i = 0; i < n; i++ ) {
//            System.out.println( "i : " + i );
            a[i] = sc.nextInt();
//            System.out.println( "a[" + i + "]" + a[i] );
        }

        // 満足度
        int point = 0;
        int[] b = new int[n];
        for( int j = 0; j < n; j++ ) {
           b[j] = sc.nextInt();
           point += b[j];
//           System.out.println( "b[" + j + "]" + b[j] );
        }
//        System.out.println( "point! : " + point );

        // 追加満足度
        int[] c = new int[n - 1];
        for( int k = 0; k < ( n -1 ); k++ ) {
           c[k] = sc.nextInt();
//           System.out.println( "c[" + k + "]" + c[k] );
        }

        for( int l = 0; l < n; l++ ) {
//            System.out.println("l : " + l);
//            System.out.println("a[l] : " + a[l]);
//            int current = (a[l] + 1 );
//            System.out.println("a[l] - 1 : " + ( a[l] - 1 ));
//            point += b[( a[l] - 1 )];
//            System.out.println("compare : " +  (n > (l+1)));
//            System.out.println("compare2 : " +( ( a[l] + 1 ) == a[( l + 1 )] ));
//            System.out.println("compare3 : " +( a[l] + 1 ));
//            System.out.println("compare4 : " + a[( l + 1 )] );
            if(  ( l + 1 ) < n && ( a[l] + 1 ) == a[( l + 1 )] ) {
//                System.out.println( "c[( l + 1 )] : " + c[( l + 1 )] );
                point += c[a[l] - 1];
            }
//            System.out.println( "point : " + point );
        }
        System.out.println( point );
     }
}
