import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        int count = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            
            if (a == b) {
                count++;
            } else {
                count = 0;
            }
            
            ans = Math.max(count, ans);
        }
        
        if (ans >= 3) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
