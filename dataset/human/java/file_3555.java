import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char x = scanner.next().charAt(0);
        char y = scanner.next().charAt(0);
        System.out.println(x > y?">":x == y?"=":"<");
    }
}
