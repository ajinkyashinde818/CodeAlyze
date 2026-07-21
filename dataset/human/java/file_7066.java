import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int k = Integer.parseInt(sc.next());
        int n = Integer.parseInt(sc.next());
        
        int[] a = new int[n];
        a[0] = Integer.parseInt(sc.next());
        int max = 0;
        for(int i = 1; i < n; i++){
            a[i] = Integer.parseInt(sc.next());
            if(a[i] - a[i-1] > max) max = a[i] - a[i-1];
        }
        if((a[0] + k - a[n-1]) > max) max = a[0] + k - a[n-1];
        
        System.out.println(k - max);
    }
}
