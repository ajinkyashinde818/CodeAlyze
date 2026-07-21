import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner sc = new Scanner(System.in);

        int d = sc.nextInt();
        int g = sc.nextInt();
        int[][] scoreList = new int[d][3];

        for (int i = 0; i < d; i++) {
            scoreList[i][0] = sc.nextInt();
            scoreList[i][1] = sc.nextInt();
            scoreList[i][2] = scoreList[i][0] * (100 * (i + 1)) + scoreList[i][1];
        }

        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < Math.pow(2, d); i++) {
            int nowBit = i;
            int index = Integer.highestOneBit(nowBit);
            int pointSum = 0;
            int count = 0;
            while (index > 0) {
                nowBit -= index;
                index = (int)(Math.log(index) / Math.log(2));
                pointSum += scoreList[index][2];
                count += scoreList[index][0];
                index = Integer.highestOneBit(nowBit);
            }
            if (pointSum < g) {
                int amari = g - pointSum;
                int maxIndex = (int)(Math.log(Integer.highestOneBit(~i & ((int) Math.pow(2, d) - 1))) / Math.log(2));
                int value =  (maxIndex + 1) * 100;
                if (amari <= (scoreList[maxIndex][0] - 1) * value) {
                    count += Math.ceil((double)amari / value);
                } else {
                    continue;
                }
            }
            ans = Math.min(ans, count);
        }

        System.out.println(ans);
    }
}
