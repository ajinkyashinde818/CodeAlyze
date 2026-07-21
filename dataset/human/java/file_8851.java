import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = Integer.parseInt(sc.next());
        int b = Integer.parseInt(sc.next());
        int k = Integer.parseInt(sc.next());
        List<Integer> list = getDivisor(getGcd(a, b));
        Collections.sort(list);
        System.out.println(list.get(list.size() - k));
    }

    // 公約数
    private static List<Integer> getDivisor(int n) {
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                list.add(i);
                if (n / i != i) {
                    list.add(n / i);
                }
            }
        }
        return list;
    }

    // 最大公約数
    private static int getGcd(int x, int y) {
        return y == 0 ? x : getGcd(y, x % y);
    }
}
