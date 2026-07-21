import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextInt();
        long b = sc.nextInt();
        
        long m = a;
        long n = b;
        long r;
        
        if(m<n)
        {
            long swap = n;
            n = m;
            m = swap;
        }
        
        while(m%n != 0)
        {
            r = m%n;
            m = n;
            n = r;
        }
        
        a /= n;
        b /= n;
        
        long ans = a*b*n;
        
        //System.out.println(a + "*" + b +"*" + n);
        System.out.println(ans);
    }
}
