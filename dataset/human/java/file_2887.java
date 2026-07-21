import java.util.Scanner;

public class Main {
    static int ans;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int hs[] = { 4, 1, 4, 1, 2, 1, 2, 1 };
        while (sc.hasNext()) {
            int ps[] = new int[8];
            for (int i = 0; i < 8; i++) {
                ps[i] = sc.nextInt();
            }
            int ans = 0;
            int max = 0;
            for (int i = 0; i < 8; i++) {
                String cs = "";
                int sum = 0;
                for (int j = 0; j < 8; j++) {
                    cs += hs[(i + j) % 8];
                    sum += Math.min(hs[(i + j) % 8], ps[j]);
                }
                if (max < sum) {
                    ans = Integer.parseInt(cs);
                    max = sum;

                } else if (max == sum) {
                    if (Integer.parseInt(cs) < ans) {
                        ans = Integer.parseInt(cs);
                    }
                }
            }
            char cs[] = Integer.toString(ans).toCharArray();
            boolean init = true;
            for (int i = 0; i < 8; i++) {
                if (init) {
                    init = false;
                } else
                    System.out.print(" ");
                System.out.print(cs[i]);
            }
            System.out.println();
        }

    }
}
