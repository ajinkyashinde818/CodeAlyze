import java.util.Scanner;


public class Main {
    static Scanner s = new Scanner(System.in);

    public static void main(String[] args) {
        while (true) {
            int n = s.nextInt();
            if (n == 0) break;

            int[] key = new int[n];

            for (int i = 0; i < n; i++) {
                key[i] = s.nextInt();
            }

            String station = s.next();
            int num = 0;

            for (int i = 0; i < station.length(); i++) {
                int ans = station.charAt(i);
                if (ans > 96) {
                    ans -= key[num];
                    if (ans < 97) {
                        ans -= 6;
                        if (ans < 65)
                            ans += 58;
                    }
                } else {
                    ans -= key[num];
                    if (ans < 65) {
                        ans += 58;
                        if (ans < 97)
                            ans -= 6;
                    }
                }

                num++;
                if(num==n)num=0;

                System.out.print((char) ans);
            }
            System.out.println();
        }
    }
}
