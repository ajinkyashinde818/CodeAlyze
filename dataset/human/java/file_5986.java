import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        if( s.contains("a") && s.contains("b") && s.contains("c")) {
            System.out.println("Yes");
        }
        else {
            System.out.print("No");
        }
    }
}
