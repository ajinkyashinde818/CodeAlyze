import java.util.*;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int compare = Integer.compare(Integer.parseInt(scanner.next(), 16), Integer.parseInt(scanner.next(), 16));
        System.out.println(compare == 0 ? "=" : compare == 1 ? ">" : "<");
    }
}
