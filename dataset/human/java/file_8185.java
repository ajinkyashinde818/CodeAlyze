import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long a = sc.nextInt();
        long b = sc.nextInt();
        sc.close();
        long lcm = (a * b) / gcd(a,b);
        System.out.println(lcm);
        
    }

    private static long gcd(long a,long b){

        if(a < b){
            long tmp = a;
            a = b;
            b = tmp;
        }

        long d = a%b;

        if(d==0)return b;
        else return gcd(b,d);
        
    }
}
