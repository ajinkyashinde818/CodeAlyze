import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        Map<Integer, ArrayList<Integer> > an = new HashMap<Integer, ArrayList<Integer> >();
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (an.containsKey(a)) {
                ArrayList al = an.get(a);
                al.add(b);
                an.put(a, al);
            } else {
                ArrayList al = new ArrayList<>();
                al.add(b);
                an.put(a, al);
            }
        }

        for (int b : an.get(1)) {
            if (!an.containsKey(b)) {
                continue;
            }

            if (an.get(b).indexOf(n) != -1) {
                System.out.println("POSSIBLE");
                System.exit(0);
            }
        }

        System.out.println("IMPOSSIBLE");
    }

}
