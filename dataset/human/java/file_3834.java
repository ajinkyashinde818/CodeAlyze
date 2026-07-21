import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int n = str.length();
        
        int count = 0;
        int left = 0;
        int right = n - 1;
        while (true) {
            char ca = str.charAt(left);
            char cb = str.charAt(right);
            
            if (ca == cb) {
                left++;
                right--;
            } else if (ca == 'x') {
                count++;
                left++;
            } else if (cb == 'x') {
                count++;
                right--;
            } else {
                System.out.println(-1);
                return;
            }
            
            if (left > right) {
                break;
            }
        }
        System.out.println(count);
    }
}
