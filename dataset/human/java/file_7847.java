import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt()-1;
        }
        boolean[] used = new boolean[n];
        used[0] = true;
        int nex = a[0];
        long size = 1L;
        for (int i = 0; i < n; i++) {
            if(used[nex]){
                break;
            }
            used[nex] = true;
            size++;
            nex = a[nex];
        }
        int ztor = 1;
        int r = nex;
        nex = a[0];
        for (int i = 0; i < size; i++) {
            if(nex == r) break;
            ztor++;
            nex = a[nex];
        }
        if(size != ztor) size -= ztor;
        int ans = 0;
        long rest = 0;
        if(ztor < k){
            k -= ztor;
            rest = k % size;
            ans = r;
        }else{
            rest = k;
        }
        for (int i = 0; i < rest; i++) {
            ans = a[ans];
        }
        System.out.println(ans+1);
        sc.close();

    }

}
