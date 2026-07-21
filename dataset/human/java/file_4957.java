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

        long a=sc.nextLong(),t=2,out=0;
        if(a%2==1){
            System.out.println(0);
        }else{
            while(true){
                t*=5;
                long c=a/t;
                if(c==0)break;
                out+=c;
            }
            System.out.println(out);
        }
    }
}
