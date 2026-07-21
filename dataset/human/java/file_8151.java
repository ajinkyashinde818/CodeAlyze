import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextInt();
        long B = sc.nextInt();
        sc.close();

        long judge = 0;

        for (int i = 1; i <= B; i++) {
            judge = A * i;
            if (judge % B == 0) {
                break;
            }
        }

        System.out.println(judge);
    }

}
