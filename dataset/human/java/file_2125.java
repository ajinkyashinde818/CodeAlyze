import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(br.readLine());
        int[] cnt = new int[11];
        for (int i = 1; i < cnt.length; ++i) {
            cnt[i] += i + cnt[i - 1];
        }
        List<Integer> list = new ArrayList<>();
        while (N != 1) {
            long choosen = N;
            for (long i = 2; i * i <= N; ++i) {
                if (N % i == 0) {
                    choosen = i;
                    break;
                }
            }
            int cntdiv = 0;
            while (N % choosen == 0) {
                cntdiv++;
                N /= choosen;
            }
            list.add(cntdiv);
            // 2 2 2 2 3 3
        }
        int res = 0;
        for (int i = 0; i < list.size(); ++i) {
            int val = list.get(i);
            int lo = 0;
            int hi = cnt.length - 1;
            int idx = -1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (cnt[mid] <= val) {
                    idx = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            res += idx;
        }
        System.out.println(res);
    }
}
