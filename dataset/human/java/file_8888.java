import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        sc.close();
        int ans = 100;
        int cnt = 0;
        while (true) {
            if (a % ans == 0 && b % ans == 0) {
                cnt++;
            }
            if (cnt == k) {
                System.out.println(ans);
                return;
            }
            ans--;
        }
    }
}
