import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int k = scan.nextInt();
        int n = scan.nextInt();
        int[] a = new int[n];
        int max = 0;
        int b = 0;
        for(int i = 0; i < n; i++){
            a[i] = scan.nextInt();
        }
        for(int i = 1; i < n; i++){
            if(a[i] - a[i - 1] > max){
                max = a[i] - a[i - 1];
                b = i;
            }
        }
        int out = Math.abs(k - a[b]) + a[b - 1];
        if(k - a[n - 1] + a[0] > max){
            out = a[n - 1] - a[0];
        }
        System.out.println(out);
    }
}
