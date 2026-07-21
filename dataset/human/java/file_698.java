import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int N = sc.nextInt();
            int R = sc.nextInt();
            System.out.println(N < 10 ? R + (100 * (10 - N)) : R);
        }
    }
}
