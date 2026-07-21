import java.util.*;

public class Main {

    Scanner sc = new Scanner(System.in);


    public static void main(String[] args) {
        new Main().run();
    }

    void run() {

        int k = sc.nextInt();
        int s = sc.nextInt();

        long res = 0;

        for (int x=0; x<=k; x++) {
            for (int y=0; y<=k; y++) {
                int z = s - (x + y);
                if (0 <= z && z <= k) res++;
            }
        }

        System.out.println(res);

    }


}
