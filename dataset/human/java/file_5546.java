import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int s = sc.nextInt();
        for (int i = 0; i < k; i++) {
            System.out.print(s + " ");
        }
        int v = s == 1 ? 2 : s - 1;
        for (int i = 0; i < n - k; i++) {
            System.out.print(v + " ");
        }
    }
}
