import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();

        int innerRating;

        if (n >= 10) {
            innerRating = r;
        } else {
            innerRating = r + 100 * (10 - n);
        }

        System.out.println(innerRating);
    }
}
