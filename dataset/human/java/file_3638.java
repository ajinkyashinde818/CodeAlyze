import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            solve(sc);
        }
    }

    public static void solve(Scanner sc) {
        String a = sc.next();
        String b = sc.next();
        System.out.println(a.compareTo(b)> 0 ? ">" : (a.equals(b) ? "=" : "<"));
    }
}
