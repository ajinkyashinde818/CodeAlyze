import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] d = new int[n][2];
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < 2 ; j++) {
                d[i][j] = sc.nextInt();
            }
        }
        int c = 0;
        for (int i = 0 ; i < n ; i++) {
            if (d[i][0] == d[i][1]) {
                c++;
            } else {
                c = 0;
            }
            if (c >= 3) {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");

    }

}
