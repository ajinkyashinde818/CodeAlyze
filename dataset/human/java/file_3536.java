import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        char x = sc.next().charAt(0);
        char y = sc.next().charAt(0);

        String result = "<";
        if (x > y) {
            result = ">";
        } else if (x == y) {
            result = "=";
        }
        System.out.println(result);
    }
}
