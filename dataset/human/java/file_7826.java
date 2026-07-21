import java.util.*;

public class Main {

    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);

        final int n = sc.nextInt();
        long k = sc.nextLong();

        final int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }


        int[] ord = new int[n+1];
        for (int i = 0; i < n+1; i++) {
            ord[i] = -1;
        }

        int v = 1;
        List<Integer> s = new ArrayList<>();
        while (ord[v] == -1) {
            ord[v] = s.size();
            s.add(v);
            v = a[v-1];
        }
        int c = s.size() - ord[v]; // loop size
        int l = ord[v]; // loopが始まる場所

        if (k < l) {
            System.out.println(s.get((int)k));
        } else {
            k -= l;
            k %= c;
            System.out.println(s.get((int)k+l));
        }
    }
}
