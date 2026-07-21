import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        int[] a = new int[n];
        Arrays.setAll(a, i -> sc.nextInt());
        sc.close();
        int[] v = new int[n+1];
        Arrays.fill(v, -1);
        ArrayList<Integer> list = new ArrayList<>();
        int c = 1;
        int l = 0;
        {
            int m = 1;
            while(v[m] == -1) {
                v[m] = list.size();
                list.add(m);
                m = a[m-1];
            }
            c = list.size() - v[m];
            l = v[m];
        }
        
        int res;
        if (k < (long)l) {
            res = list.get((int)k);
        } else {
            k -= l;
            k %= c;
            res = list.get(l+(int)k);
        }
        
        System.out.println(res);
    }
}
