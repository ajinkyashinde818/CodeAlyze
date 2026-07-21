import java.util.*;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        System.out.println(scanner.next().matches("abc|acb|bac|bca|cab|cba") ? "Yes" : "No");
    }
}
