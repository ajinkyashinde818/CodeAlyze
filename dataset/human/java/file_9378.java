import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] D1 = new int[N];
        int[] D2 = new int[N];
        for (int i = 0; i < N; i++) {
            D1[i] = sc.nextInt();
            D2[i] = sc.nextInt();
        }

        boolean ok = false;
        for (int i = 0; i < N-2; i++) {
            if (D1[i] == D2[i] && D1[i+1] == D2[i+1] && D1[i+2] == D2[i+2]) {
                ok = true;
                break;
            }
        }
        System.out.println(ok ? "Yes" : "No");
    }
}
