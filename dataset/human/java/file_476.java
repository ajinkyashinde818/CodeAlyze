import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        //コード
        Scanner scanner = new Scanner(System.in);

        Integer n = Integer.parseInt(scanner.next());
        Integer r = Integer.parseInt(scanner.next());
        Integer max_num = 10;

        int inside_rating = r;

        if (n < max_num) {
            inside_rating += 100 * (10 - n);
        }

        System.out.println(inside_rating);

    }
}
