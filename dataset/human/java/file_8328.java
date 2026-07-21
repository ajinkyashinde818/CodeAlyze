import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();

        int s = (A >= B) ? A : B;
        int f = (A >= B) ? B : A;
        long ans = s;
        for (int i = 1; i <= f; i++) {
            ans *= i;
            if(ans%f == 0){
//                System.out.println(i);
                System.out.println(ans);
                return;
            }
            ans /= i;
        }
    }

}
