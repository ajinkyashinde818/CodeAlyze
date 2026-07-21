import java.util.*;
public class Main
{
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); int [] a = new int [n+1]; long k = sc.nextLong();
        for (int i = 1; i <= n; i++) a[i] = sc.nextInt();
        Set<Integer> seen = new HashSet<>();
        ArrayList<Integer> st = new ArrayList<>();
        int cur = 1;
        while (!seen.contains(cur)) {
            st.add(cur);
            seen.add(cur);
            cur = a[cur];
        }
        int offset = 0; int cycle = -1; int temp = st.size();
        for (int i = 0; i < temp; i++) {
            if (st.get(i) == cur) {
                offset = i; cycle = temp - offset; break;
            }
        }
        if (k < st.size()) {
            System.out.println(st.get((int)k));
        } else {
            int mod = (int) ((k - offset)%cycle) + offset;
            System.out.println(st.get(mod));
        }
    }


}
