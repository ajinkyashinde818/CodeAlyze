import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        try (Scanner in = new Scanner(System.in)) {
            int N = in.nextInt();
            System.out.println((N % 10 == 9 || (N / 10) % 10 == 9) ? "Yes" : "No");
        }
    }
}
