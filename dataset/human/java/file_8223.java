import java.util.Scanner;

/**
 * C - Snack
 * 高橋君はパーティを企画しています。
 * パーティーでは参加者に 1 人 1 個以上のお菓子を配る予定です。
 * 高橋君は参加者の人数が A 人か B 人のどちらかになるだろうという予想を立てました。
 * どちらの場合でも均等に配りきることができるようなお菓子の個数の最小値を求めてください。
 * ただし、 1 個のお菓子を分割して複数人で分けることはできないものとします。
 */
public class Main {

    public static void main( String[] args ) {

        Scanner sc = new Scanner( System.in );
        // 入力値
        int a = sc.nextInt();
        int b = sc.nextInt();

        System.out.println( lcm( a, b ) );

        sc.close();
    }

    /*
     *  最小公倍数lcm
     */
    static long lcm ( int a, int b ) {
        int temp;
        long c = a;
        c *= b;
        while( ( temp = a % b ) != 0 ) {
            a = b;
            b = temp;
        }
        return c / b ;
    }
}
