import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] array = new int[n];
        int dif = 0;
        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                dif = Math.max(dif, (k - array[i]) + array[0]);
            } else {
                dif = Math.max(dif, array[i+1] - array[i]);
            }
        }
        
        System.out.println(k -dif);
    }
}
