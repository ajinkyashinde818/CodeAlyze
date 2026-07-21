import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
    
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int K = sc.nextInt();
        
        int gcd = GCD(A, B);
        
        int div = 2;
        int cnt = 1;
        while( cnt < K ){
            if( gcd % div == 0 ){
                cnt++;
            }
            div++;
        }
        
        System.out.println( gcd/(div-1) );

    }
    
    static int GCD(int x, int y){
        if( y == 0) return x;
        return GCD(y, x % y);
    }
}
