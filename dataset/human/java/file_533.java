import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int contests = sc.nextInt();
        int rating = sc.nextInt();
        if (contests >= 10) {
            System.out.println(rating);
        } else {
            System.out.println(rating + 100 * (10 - contests));
        }
    }
}
