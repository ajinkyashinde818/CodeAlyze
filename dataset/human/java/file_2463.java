import java.util.*;

public class Main {
    private static final Scanner scn = new Scanner(System.in);
    private static final int[] MCXI_NUM = {1000, 100, 10, 1};
    private static final char[] MCXI_CHAR = {'m', 'c', 'x', 'i'};

    public static void main(String[] args) {
        for(int n = scn.nextInt(); n > 0; n--) {
            System.out.println(encode(decode(scn.next()) + decode(scn.next())));
        }
    }

    private static int decode(String mcxi) {
        int ans = 0;
        int buf = 1;
        for(char elm : mcxi.toCharArray()) {
            if(Character.isDigit(elm)) {
                buf = elm - '0';
            } else {
                ans += buf * convert(elm);
                buf = 1;
            }
        }
        return ans;
    }

    private static int convert(char mcxi) {
        for(int i = 0; i < MCXI_CHAR.length; i++) {
            if(MCXI_CHAR[i] == mcxi) {
                return MCXI_NUM[i];
            }
        }
        return 0;
    }

    private static String encode(int num) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < MCXI_NUM.length; i++) {
            sb.append(num / MCXI_NUM[i] > 1 ? num / MCXI_NUM[i] : "");
            sb.append(num / MCXI_NUM[i] > 0 ? MCXI_CHAR[i] : "");
            num = num % MCXI_NUM[i];
        }
        return sb.toString();
    }
}
