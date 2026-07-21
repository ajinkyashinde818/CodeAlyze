import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        for (int i = 0 ; i < m ; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }
        Set<Integer> aSet = new HashSet<>();
        List<Integer> bList = new ArrayList<>();
        for (int i = 0 ; i < m ; i++) {
            if (a[i] == 1) {
                aSet.add(b[i]);
            }
            if (b[i] == n) {
                bList.add(a[i]);
            }
        }
        int totalLength = aSet.size() + bList.size();
        aSet.addAll(bList);

        if (aSet.size() == totalLength) {
            System.out.println("IMPOSSIBLE");
        } else {
            System.out.println("POSSIBLE");
        }

    }

}
