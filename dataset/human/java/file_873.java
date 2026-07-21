import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        // 変数宣言
        final int MAX = 10;
        int ratingDispray;
        int ratingInternal;
        int joinContestCount;

        // 標準入力
        Scanner sc = new Scanner(System.in);
        joinContestCount = sc.nextInt();
        ratingDispray = sc.nextInt();

        sc.close();

        // 演算処理
        if( joinContestCount >= MAX ){
            ratingInternal = ratingDispray;
        }else{
            ratingInternal = ratingDispray + (100 * (10 - joinContestCount ));
        }

        // 出力
        System.out.println( ratingInternal );
    }
}
