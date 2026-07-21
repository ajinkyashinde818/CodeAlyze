import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        String str1 = sc.next();
        char[] c1 = str1.toCharArray();
        Arrays.sort(c1);
        String str2 = sc.next();
        char[] c2 = str2.toCharArray();
        Arrays.sort(c2);
        
        int i = 0;
        int j = c2.length - 1;
        while (true) {
            int a = c1[i] - 'a'; // 'b' -> 1
            int b = c2[j] - 'a'; // 'b' -> 1
            if (a < b) {
                System.out.println("Yes");
                return;
            } else if (a > b) {
                System.out.println("No");
                return;
            }
            
            i++;
            j--;
            
            if (j == -1) {
                System.out.println("No");
                return;
            } else if (i == c1.length) {
                System.out.println("Yes");
                return;
            }
        }
    }
}
