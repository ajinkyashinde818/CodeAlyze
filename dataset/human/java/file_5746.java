import java.util.Scanner;

class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String s = sc.next();
        if (s.contains("a") && s.contains("b") && s.contains("c")) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
