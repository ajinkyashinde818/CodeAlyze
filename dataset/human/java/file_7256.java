import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        int[] dist = new int[n];
        for(int i = 0; i < n; i++){
            if(i != n-1){
                dist[i] = a[i+1] - a[i];
            } else {
                dist[i] = a[0]+k - a[i];
            }
        }
        Arrays.sort(dist);
        System.out.print(k - dist[n-1]);
    }
}
