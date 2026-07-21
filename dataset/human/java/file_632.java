import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int R = sc.nextInt();
        int ans = 100 * (10-N) + R;
        if (N >= 10 )
            System.out.println(R);
        else
            System.out.println(ans);
    }
}
