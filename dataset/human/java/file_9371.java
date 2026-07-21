import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int zorocount = 0;
        for (int i = 0; i < N; i++){
            int d1 = sc.nextInt();
            int d2 = sc.nextInt();
            if (d1 == d2){
                zorocount++;
            }else {
                zorocount = 0;
            }
            if (zorocount > 2){
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
}
