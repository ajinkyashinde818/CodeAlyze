import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        String[] values = line.split(" ");
        long a = Long.parseLong(values[0]);
        long b = Long.parseLong(values[1]);
        if (a < 10) {
            b += (100 * (10 - a));
        }
        System.out.println(b);
    }
}
