import java.util.*;
import java.util.stream.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int R = sc.nextInt();
        int res = R + 100 * (10 - N <= 0 ? 0 : 10 - N);
        System.out.println(res);
    }
}
