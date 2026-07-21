import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long total = 0;
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();
            total += num;
            array[i] = num;
        }
        long minDiff = Long.MAX_VALUE;
        long aSum = 0;
        for(int i = 0; i < n - 1; i++) {
            aSum += array[i];
            long bSum = total - aSum;
            long diff = Math.abs(aSum - bSum);
            minDiff = Math.min(minDiff, diff);
        }
        System.out.println(minDiff);
    }
}
