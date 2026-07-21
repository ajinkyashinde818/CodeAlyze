import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = Integer.parseInt(sc.next());
        int r = Integer.parseInt(sc.next());
        int ans = (n >= 10) ? r : r + 100 * (10 - n);
        System.out.println(ans);
    }
}
