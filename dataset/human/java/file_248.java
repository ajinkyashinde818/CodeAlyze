import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] nums = new long[n];

        int minusNums = 0;
        long min = Long.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            long tmp = sc.nextLong();

            if (tmp < 0) {
                minusNums++;
            }

            tmp = tmp < 0 ? -tmp :tmp;
            if (tmp < min) {
                min = tmp;
            }

            nums[i] = tmp;
        }


        if(minusNums % 2 == 0) {
            min = 0L;
        }

        System.out.println(Arrays.stream(nums).sum() - min - min);

    }

}
