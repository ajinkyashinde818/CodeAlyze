import java.util.*;

class Main{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        int max_dist = 0;
        a[0] = sc.nextInt();
        for(int i=0;i<n-1;i++){
            a[i+1] = sc.nextInt();
            max_dist = Math.max(max_dist, a[i+1]-a[i]);
        }
        max_dist = Math.max(max_dist, (k-a[n-1])+a[0]);
        System.out.println(k-max_dist);
    }
}
