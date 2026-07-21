import java.util.Scanner;

public class Main {

    static int MOD = 1000000007;
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        int[] a = new int[m];
        for(int i = 0; i < m; i++){
            a[i] = Integer.parseInt(sc.next());
        }
        
        int[] f = new int[n+1];
        f[0] = 1;
        f[1] = 1;
        for(int i = 2; i <= n; i++){
            f[i] = (f[i-2] + f[i-1]) % MOD;
        }
        
        long count = 1;
        int length;
        if(m == 0){
            count = f[n];
        }else{
            length = a[0];
            if(length != 0){
                count = (count * f[length -1]) % MOD;
            }
            for(int i = 0; i < m-1; i++){
                length = a[i+1] - a[i] -1;
                if(length == 0){
                    System.out.println(0);
                    return;
                }
                count = (count * f[length -1]) % MOD;
            }
            length = n - a[m-1];
            if(length != 0){
                count = (count * f[length -1]) % MOD;
            }
        }
        
        System.out.println(count);
    }
}
