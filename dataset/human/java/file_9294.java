import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int N = Integer.parseInt(sc.next());
            int count = 0; String result = "No";
            for (int i = 0; i < N; i++) {
                int d1 = Integer.parseInt(sc.next());
                int d2 = Integer.parseInt(sc.next());
                if (d1 == d2) {
                    count++;
                } else {
                    count = 0;
                }
                if (count == 3) {
                    result = "Yes";
                    break;
                }
            }
            System.out.println(result);
        }
    }

}
