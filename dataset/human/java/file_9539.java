import java.util.*;

public class Main {

    Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        new Main().run();
    }

    void run() {

        int n = sc.nextInt();
        boolean flag = false;
        int cnt = 0;
        for (int i=0; i<n; i++) {
            int s = sc.nextInt();
            int t = sc.nextInt();
            if (s == t) cnt++;
            else cnt = 0;
            if (3 <= cnt) flag = true;
        }

        if (flag) System.out.println("Yes");
        else System.out.println("No");
    }


}
