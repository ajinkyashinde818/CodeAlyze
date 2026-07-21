import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static String[] marks = {"i", "x", "c", "m"};

    static int calc(String mcxi) {
        int ans = 0;
        String[] tokens = mcxi.split("");
        for (int i = 0; i < tokens.length; i++) {
            int ind = Arrays.asList(marks).indexOf(tokens[i]);
            if (i != 0 && !Arrays.asList(marks).contains(tokens[i-1])) {
                // previous token is number
                ans += Integer.parseInt(tokens[i-1]) * Math.pow(10, ind);
            } else {
                ans += Math.pow(10, ind);
            }
        }
        return ans;
    }

    static String createMCXI(int num) {
        String str = "";
        int n = num;
        int c;
        for (int i = 3; i >= 0; i--) {
            c = n / (int)Math.pow(10, i);
            n = n % (int)Math.pow(10, i);
            if (c != 0) {
                if (c != 1)
                    str += c;
                str += marks[i];
            }
        }

        return str;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine().trim());
        String[] str;

        for (int i = 0; i < n; i++) {
            str = sc.nextLine().split(" ");
            System.out.println(createMCXI(calc(str[0]) + calc(str[1])));
        }
    }
}
