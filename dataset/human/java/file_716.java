import java.util.*;

public class Main {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); //コンテスト参加回数
        int r = sc.nextInt(); //表示レーティング

        if(n>10){
          r=r;
        }else{
          r=r+(100*(10-n));
        }

        // 出力
        System.out.println(r);
    }
}
