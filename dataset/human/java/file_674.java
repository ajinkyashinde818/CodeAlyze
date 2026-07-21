import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // 数値の入力
        int a = sc.nextInt();
        int b = sc.nextInt();

        int answer  = 0;
        
        if(a > 10) {
        	answer = b;
        }else {
        	answer =b + ( 100 * (10 -a));
        }

            System.out.println(answer);
    }
}
