import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        HashSet<Integer> a = new HashSet<>();
        HashSet<Integer> b = new HashSet<>();
        for (int i = 0; i < m; i++) {
            int tmpa = sc.nextInt();
            int tmpb = sc.nextInt();
            if(tmpa == 1) {
                a.add(tmpb);
            }
            if(tmpb == n) {
                b.add(tmpa);
            }
        }
        for (int aa : a) {
            if(b.contains(aa)) {
                System.out.println("POSSIBLE");
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
