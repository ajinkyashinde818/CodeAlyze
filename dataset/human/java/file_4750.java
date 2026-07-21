import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] arr = sc.next().toCharArray();
        int length = arr.length + 2;
        int[] inputs = new int[length];
        for (int i = 1; i < length - 1; i++) {
            inputs[i] = arr[i - 1] - '0';
        }
        int[][] dp = new int[length][2];
        dp[0][0] = 0;
        dp[0][1] = Integer.MAX_VALUE / 10;
        for (int i = 1; i < length; i++) {
            int x = inputs[length - i - 1];
            dp[i][0] = Math.min(getCount(x) + dp[i - 1][0], getCount(x + 1) + dp[i - 1][1]);
            dp[i][1] = Math.min(getReturn(x) + dp[i - 1][0], getReturn(x + 1) + dp[i - 1][1]);
        }
        System.out.println(dp[length - 1][0]);
    }
    
    static int getCount(int x) {
        switch (x) {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 3;
            case 4:
                return 4;
            case 5:
                return 5;
            case 6:
                return 6;
            case 7:
                return 7;
            case 8:
                return 8;
            case 9:
                return 9;
            case 10:
                return 1;
        }
        return 0;
    }
    
    static int getReturn(int x) {
        switch (x) {
            case 0:
                return Integer.MAX_VALUE / 10;
            case 1:
                return 9;
            case 2:
                return 8;
            case 3:
                return 7;
            case 4:
                return 6;
            case 5:
                return 5;
            case 6:
                return 4;
            case 7:
                return 3;
            case 8:
                return 2;
            case 9:
                return 1;
            case 10:
                return 0;
        }
        return 0;
    }
}
