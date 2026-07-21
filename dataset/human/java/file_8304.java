import java.util.*;
public class Main
{
    static int gcd(int b,int a)
    {
        if(b%a==0)
        return a;
        return gcd(a,b%a);
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        long gc;
        if(a>b)
        gc=gcd(a,b);
        else
        gc=gcd(b,a);
        long mul=(long)a*b;
        System.out.println(mul/gc);
    }
}
