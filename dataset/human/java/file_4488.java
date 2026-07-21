import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = a + b;
        int ans = 0;
        if (a + b >= c) { // 全解毒
            ans = b + c;
        } else {
            int sa = c - (a + b);
            ans = c + b - sa + 1;
        }
        System.out.println(ans);
    }
}
