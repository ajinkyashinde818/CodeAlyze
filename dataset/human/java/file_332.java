import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] nums = new int[n];

        int numNeg = 0;
        long sum = 0;
        int minMag = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();

            sum += Math.abs(nums[i]);

            if (nums[i] < 0) {
                numNeg++;
            }

            minMag = Math.min(minMag, Math.abs(nums[i]));
        }

        if (numNeg % 2 == 0) {
            System.out.println(sum);
        } else {
            System.out.println(sum - 2 * minMag);
        }
    }
}
