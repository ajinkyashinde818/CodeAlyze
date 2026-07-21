import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int[] arya = new int[n];
        int[] aryb = new int[n];
        int[] aryc = new int[n-1];
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(sc.next());
            arya[i] = a;
        }
        for (int i = 0; i < n; i++) {
            int b = Integer.parseInt(sc.next());
            aryb[i] = b;
        }
        for (int i = 0; i < n - 1; i++) {
            int c = Integer.parseInt(sc.next());
            aryc[i] = c;
        }
        int temp = -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += aryb[arya[i] - 1];
            if (temp - arya[i] == -1) {
                ans += aryc[temp - 1];
            }
            temp = arya[i];
        }
        System.out.println(ans);
    }
}
