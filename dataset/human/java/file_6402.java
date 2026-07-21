import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int max = Integer.parseInt(sc.next());
        int target = Integer.parseInt(sc.next());
        int cnt = 0;
        for (int i = 0; i <= max; i++) {
            for (int j = 0; j <= max; j++) {
                int total = i + j;
                if (target - total <= max && target - total >= 0) {
                    cnt++;
                }
            }
        }
        System.out.println(cnt);
    }
}
