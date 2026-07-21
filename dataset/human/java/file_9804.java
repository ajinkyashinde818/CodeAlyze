import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        int x = Integer.parseInt(sc.next());
        int[] c = new int[n];
        int[] sum = new int[m];
        List<Integer> idx = new ArrayList<>();
        List<List<Integer>> list = new ArrayList<>();
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            idx.add(i);
            int cc = Integer.parseInt(sc.next());
            c[i] = cc;
            List<Integer> templist = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                int temp = Integer.parseInt(sc.next());
                sum[j] += temp;
                templist.add(temp);
            }
            list.add(templist);
        }
        for (int i = 0; i < m; i++) {
            if (sum[i] < x) {
                System.out.println(-1);
                return;
            }
        }
        for (int i = 0; i < (1 << n); i++) {
            int tempAns = 0;
            int[] tempSum = new int[m];
            for (int j = 0; j < n; j++) {
                if ((i >> j & 1) == 1) {
                    tempAns += c[j];
                    for (int k = 0; k < m; k++) {
                        tempSum[k] += list.get(j).get(k);
                    }
                }
            }
            boolean isOK = true;
            for (int j = 0; j < m; j++) {
                if (tempSum[j] < x) {
                    isOK = false;
                    break;
                }
            }
            if (isOK) {
                ans = Math.min(ans, tempAns);
            }
        }
        System.out.println(ans);
    }
}
