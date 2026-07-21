import java.util.Scanner;

/**
 * A - Beginner
 * 高橋君はプログラミングコンテストサイト「ButCoder」の会員です。
 * ButCoder の会員には 2 つのレーティング 内部レーティング と 表示レーティング が割り当てられています。
 * 表示レーティングは、その会員のコンテスト参加回数が 10 以上のときは内部レーティングに等しく、
 * そうでないときは、会員のコンテスト参加回数を K として、内部レーティングから 100×(10−K) を引いたものになります。
 * 高橋君のコンテスト参加回数が N で表示レーティングが R であるとき、高橋君の内部レーティングを求めてください。
 */
public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner( System.in );
        // 参加回数
        int n = sc.nextInt();
        // 表示レーティング
        int r = sc.nextInt();
        // 参加回数が10回以上の場合、表示レーティングと同一値
        if( n >= 10 ) {
            System.out.println( r );
        }
        else {
            System.out.println( r + ( 100 * ( 10 - n ) ) );
        }

        sc.close();
    }
}
