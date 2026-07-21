import java.io.*;
import java.util.*;
public class Main {

    public static void main(String args[]) throws Exception {
        int minCnt = Integer.MAX_VALUE;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long target = sc.nextLong();
        
        int[] numArr = new int[n];
        int[] scores = new int[n];
        for(int i = 0; i < n; i++) {
            numArr[i] = sc.nextInt();
            scores[i] = sc.nextInt();
        }
        for(int i = 0; i < Math.pow(2, n); i++) {
            long sum = 0;
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if((i >> j & 1) == 1) {
                    sum += scores[j];
                    sum += numArr[j] * (j + 1) * 100;
                    cnt += numArr[j];
                }
            }
            if(sum < target) {
                int j = n - 1;
                for(; j >=0; j--)
                    if((i >> j & 1) == 0)
                        break;

                for(int k = 0; k < numArr[j] - 1; k++) {
                    sum += (j + 1) * 100;
                    cnt++;
                    if(sum >= target)
                        break;
                }
            }
            if(sum >= target) {
                minCnt = Math.min(minCnt, cnt);
            }
        }
        System.out.println(minCnt);
    }
}
