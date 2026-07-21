import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String n = scanner.nextLine();
        String fes = "FESTIVAL";
        System.out.println(n.substring(0, n.length() - fes.length()));
    }
}
