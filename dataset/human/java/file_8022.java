import java.util.*;

public class Main{

    static long gcd(long a,long b){
        if(b==0)return a;
        return gcd(b,a%b);
    }

    static long lcm(long a,long b){
        return a/gcd(a,b)*b;
    }
    public static void main(String[] srgs){
        Scanner sc=new Scanner(System.in);

        long a=sc.nextInt();
        long b=sc.nextInt();
        System.out.println(lcm(a,b));
    }
}
