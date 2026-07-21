import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt(), n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i ++)
            nums[i] = scanner.nextInt();
        int max = k - nums[n - 1] + nums[0];
        for (int i = 1; i < n; i ++)
            max = Math.max(nums[i] - nums[i - 1], max);
        System.out.println(k - max);
    }

}
