import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int nega = 0;
        long ans = 0;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            if (a[i] < 0)
                nega++;
            ans += Math.abs(a[i]);
            min = Math.min(min, Math.abs(a[i]));
        }

        if (nega % 2 == 0)
            System.out.println(ans);
        else
            System.out.println(ans - min * 2);

        sc.close();
    }
}
