import java.util.*;
import java.lang.Math;
import java.math.BigDecimal;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = gcd(A, B);
        System.out.println((long)A * (long)B / C);
    }
    
    public static int gcd(int A, int B){
        int tmp = 0;
        if(A < B){
            tmp = A;
            A = B;
            B = tmp;
        }
        int C = A % B;
        while(C != 0){
            A = B;
            B = C;
            C = A % B;
        }
        return B;
    }
}
