import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int R = sc.nextInt();
        int ans = 0;

        if (N >= 10) {
            ans = R;
        }
        else {
            ans = R + (100*(10-N));
        }
        System.out.println(ans);
    }
}
