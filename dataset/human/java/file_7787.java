import java.util.Scanner;

class Main {
    public static void main(final String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int dist = 1;
        int count = 0;
        int[] ans = new int[n];
        int[] aaa = new int[n];
        int[] check = new int[n];
        int mod = 0;
        int sub = 0;

        while (true) {
            count++;
            dist = a[dist - 1];
            if (k == (long) count) {
                System.out.println(dist);
                return;
            }
            check[dist - 1] ++;    
            if (check[dist - 1] == 2) {
                sub = ans[dist - 1];
                mod = count - ans[dist - 1];
                break;
            }
            ans[dist - 1] = count;
            aaa[count] = dist;
        }

        System.out.println(aaa[(int) (((k - sub) % mod) + sub)]);

    }
}
