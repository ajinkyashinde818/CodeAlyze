import java.util.Scanner;

public class Main {


    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[][] info = new int[N][2];

        for (int i = 0; i < N; i++) {
            info[i][0] = sc.nextInt();
            info[i][1] = sc.nextInt();
        }

        int z = 0;
        for (int i = 0; i < N; i++) {

            if (info[i][0] == info[i][1]) {
                z++;
            } else {
                z = 0;
            }

            if (z == 3) {
                System.out.println("Yes");
                return;

            }
        }
        System.out.println("No");
    }
}
