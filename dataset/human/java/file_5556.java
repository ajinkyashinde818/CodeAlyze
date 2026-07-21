import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int s = sc.nextInt();
        
        int[] array = new int[n];
        if (s == 1000000000) {
            Arrays.fill(array, 999999999);
        } else {
            Arrays.fill(array, 1000000000);
        }
        
        for (int i = 0; i < k; i++) {
            array[i] = s;
        }
        
        for (int i = 0; i < n; i++) {
            System.out.print(array[i]);
            
            if (i != n-1) {
                System.out.print(" ");
            } else {
                System.out.println();
            }
        }
    }
}
