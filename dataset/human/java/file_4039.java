import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] dish = new int[n];
        int[] sat = new int[n];
        int[] plus = new int[n - 1];
        for (int i = 0; i < n; i++) {
            dish[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            sat[i] = sc.nextInt();
        }
        for (int i = 0; i < n - 1; i++) {
            plus[i] = sc.nextInt();
        }
        int sum = 0;
        int before = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int current = dish[i];
            sum += sat[current - 1];
            if (before + 1 == current) {
                sum += plus[before - 1];
            }
            before = current;
        }
        System.out.println(sum);
    }
}
