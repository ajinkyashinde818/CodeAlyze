import java.util.*;

public class Main{

    public static void main(String args[]){

        int[] num = new int[100];
        // スキャナーの宣言
        Scanner sc = new Scanner(System.in);
        // 整数の入力
		int a = sc.nextInt();
        // スペース区切りの整数の入力
        int b = sc.nextInt();
        int k = sc.nextInt();
        int n = 0;
        for(int i = 1; i < Math.min(a, b) + 1; i++){
            if(a % i == 0 && b % i == 0){
                num[n] = i;
                n++;
            }
        }
        // 出力
        System.out.println(num[n - k]);

    }

}
