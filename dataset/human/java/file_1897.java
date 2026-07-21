import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt();
        long g = sc.nextLong();
        int[] p = new int[d];
        int[] c = new int[d];
        for (int i = 0; i < d; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }
        sc.close();

//        System.out.println(list);

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < pow(2, d); i++) {
            String str = toBinaryString(i, d);
//            System.out.println(str);
            int num = 0;
            long sum = 0;
            for (int j = 0; j < str.length(); j++) {
                if (str.charAt(j) == '1') {
                    num += p[j];
                    sum += 100 * (j + 1) * p[j] + c[j];
                }
            }

//            System.out.println("sum=" + sum + ", num=" + num);
            if (sum >= g && num <= ans) {
                ans = num;
            }

            int lastZeroIndex = str.lastIndexOf('0');
            if (lastZeroIndex >= 0) {
                for (int j = 0; j < p[lastZeroIndex]; j++) {
                    sum += 100 * (lastZeroIndex + 1);
                    num++;
                    if (sum >= g && num <= ans) {
                        ans = num;
                    }
                }
            }
        }
        System.out.println(ans);
    }

    static long sum(List<Long> list) {
        long ret = 0;
        for (Long l : list) {
            ret += l;
        }
        return ret;
    }

    // baseのn乗を計算を返す
    static int pow(int base, int n) {
        int ret = 1;
        for (int i = 0; i < n; i++) {
            ret *= base;
        }
        return ret;
    }

    // intをlength桁のbit文字列に変換
    static String toBinaryString(int input, int length) {
        return toBinaryString(input).substring(29 - length);
    }

    // intを29桁のbit文字列に変換
    static String toBinaryString(int input) {
        String ret = "";
        int max = 0x10000000;
        for (int i = 0; i < 29; i++) {
            int tmp = input / max;
            ret += tmp;
            input %= max;
            max /= 2;
        }
        return ret;
    }

}
