import java.util.*;
class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        int[] a = new int[m], b = new int[m];
        for(int i = 0; i < m; i++){
            a[i] = sc.nextInt() - 1;
            b[i] = sc.nextInt() - 1;
        }
        boolean[] aa = new boolean[n], bb = new boolean[n];
        Arrays.fill(aa, false);
        Arrays.fill(bb, false);
        for(int i = 0; i < m; i++){
            if(a[i] == 0) bb[b[i]] = true;
            if(b[i] == n-1) aa[a[i]] = true;
        }
        String ans = "IMPOSSIBLE";
        for(int i = 0; i < n; i++)
            if(aa[i] == true && bb[i] == true)
                ans = "POSSIBLE";
        System.out.println(ans);
    }
}
