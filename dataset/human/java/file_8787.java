import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        q_2();
    }

    private static void q_1() {
        try (Scanner scan = new Scanner(System.in)) {
            int a = scan.nextInt();
            int b = scan.nextInt();
            int c = scan.nextInt();

            System.out.println(b / a < c ? b / a : c);
        }
    }

    private static void q_2() {
        try(Scanner scan = new Scanner(System.in)) {
            int a = scan.nextInt();
            int b = scan.nextInt();
            int c = scan.nextInt();

            int min = Math.min(a, b);

            int cnt = 0;
            for (; min >= 1; min--) {
                if (a % min == 0 && b % min == 0) {
                    cnt ++;
                    if(cnt == c) {
                        break;
                    }
                }
            }

            System.out.println(min);
        }
    }
}
