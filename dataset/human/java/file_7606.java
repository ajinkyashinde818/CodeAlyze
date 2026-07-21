import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        int[] a = new int[n+1];
        for (int i=1;i<=n;i++)a[i]=sc.nextInt();
        int[] steps = new int[n+1];
        int cur=1 , d=1;
        while (k>0){
            int next = a[cur];
            if (steps[cur]>0){
                int m = d - steps[cur];
                k = (k-1)%m+1;
            }
            steps[cur]=d++;
            k--;
            cur = next;
        }
        System.out.println(cur);
    }
}
