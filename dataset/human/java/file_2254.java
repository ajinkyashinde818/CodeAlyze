import java.util.*;

public class Main {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] imos = new int[100003];
        for (int i = 0; i < n; i++) {
            imos[sc.nextInt()]++;
            imos[sc.nextInt() + 1]--;
        }
        int max = 0;
        for (int i = 1; i < imos.length; i++) {
            imos[i] += imos[i - 1];
            if (imos[i] >= i - 1) {
                max = Math.max(max, i - 1);
            }
        }
        System.out.println(max);
    }
}
