import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt();
        int g = sc.nextInt();
        int[] p = new int[d];
        int[] c = new int[d];
        int[] sum = new int[d];
        long ans = 0;
        for (int i = 0; i < d; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
            sum[i] = p[i] * (i + 1) * 100 + c[i];
            ans += p[i];
        }
        int maxpos = -1;
        int kaisuu = 0;

        for (int bit = 0; bit < (1 << d); bit++) {
            long wa = 0;
            maxpos = 0;
            kaisuu = 0;
            for (int i = 0; i < d; i++) {
                if ((bit & (1 << (d - 1 - i))) != 0) {

                    wa += sum[i];
                    kaisuu += p[i];
                } else {
                    maxpos = i;
                }
            }
            if (wa < g) {
                // maxposを追加していく
                for (int j = 0; j < p[maxpos]; j++) {
                    wa += (maxpos + 1) * 100;
                    kaisuu++;
                    if (wa >= g) {
                        if (kaisuu < ans) {
                            ans = kaisuu;
                            break;
                        }
                    }
                }
            } else {
                if (kaisuu < ans) {
                    ans = kaisuu;

                }
            }

        }
        System.out.println(ans);

        sc.close();
    }
}
