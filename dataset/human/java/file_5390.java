import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            solve(in);
        }
    }

    private static void solve(Scanner in) {
        System.out.println(in.nextInt() < 1200 ? "ABC" : "ARC");
    }
}
