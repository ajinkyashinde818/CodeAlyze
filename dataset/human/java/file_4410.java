import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] dishes = new int[n];
        for (int i = 0; i < n; i++) {
            dishes[i] = sc.nextInt()-1;
        }
        int[] utility = new int[n];
        for (int i = 0; i < n; i++) {
            utility[i] = sc.nextInt();
        }
        int[] additionalUtility = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            additionalUtility[i] = sc.nextInt();
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += utility[dishes[i]];
            if (i > 0 && dishes[i] == dishes[i-1]+1) {
                ans += additionalUtility[dishes[i-1]];
            }
        }
        System.out.println(ans);
    }
}
