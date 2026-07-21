import java.math.*;
import java.util.*;
import java.io.*;
  
public class Main { 
  
    static BufferedReader in;
    static PrintWriter out = new PrintWriter(System.out);
    static String file = "../in";
    static int test = 10; // 0 for local testing, 1 for std input
    static int inf = 1_000_000, mod = 1_000_000_007;



    void swap(int[]ary, int i, int j)
    {
        int t = ary[i];
        ary[i] = ary[j];
        ary[j] = t;
    }
    
    String[] split() throws Exception
    {
        return in.readLine().split(" ");
    }

    int readInt() throws Exception
    {
        return Integer.valueOf(in.readLine());
    }

    long[] toLongArray() throws Exception
    {
        String[] sp = split();
        int n = sp.length;
        long[] ary = new long[n];
        for(int i = 0; i < n; i++) ary[i] = Long.valueOf(sp[i]);
        return ary;
    }

    int[] toIntArray() throws Exception
    {
        String[] sp = split();
        int n = sp.length;
        int[] ary = new int[n];
        for(int i = 0; i < n; i++) ary[i] = Integer.valueOf(sp[i]);
        return ary;
    }

    String reverse(String str)
    {
        return new StringBuilder(str).reverse().toString();
    }


    long pow(long a, int pow)
    {
        long res = 1;
        while(pow > 0)
        {
            if(pow % 2 != 0) {
                res *= a;
                res %= mod;
            }
            a = a * a;
            a %= mod;
            pow /= 2;
        }

        return res;
    }

    public static void main(String[] args) throws Exception
    {
        int _k = Integer.valueOf("1");
        if(test > 0) in = new BufferedReader(new InputStreamReader(System.in));
        else in = new BufferedReader(new FileReader(file));
        if(test < 0) {String[] str = in.readLine().split(" ");
        char[] gg = in.readLine().toCharArray();}
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
        // System.out.println((-100 + 0) / 2);

        
        new Main().d();
        out.flush();
    }

    void e() throws Exception
    {
        int n = readInt();
        long[] a = new long[n], b = new long[n];
        for(int i = 0; i < n; i++)
        {
            long[] ary = toLongArray();    
            a[i] = ary[0];
            b[i] = ary[1];
        }
        
        long re = n;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(a[i] * a[j] + b[i] * b[j] != 0) re++;
            }
        }
        System.out.println(re);
        
    }

    void d() throws Exception
    {
        long n = Long.valueOf(in.readLine());
        int step = 0;
        int sqrt = (int) Math.sqrt(n);
        for(int i = 2; i < sqrt; i++)
        {
            if(n % i == 0)
            {
                // System.out.printf("...%d\n", i);
                int counter = 0;
                while(n % i == 0)
                {
                    n /= i;
                    counter++;
                }
                // System.out.printf("%d %d\n", i, counter);
                step += count(counter);
            }
        }
        if(n > 1) step++;
        
        System.out.println(step);
    }

    int count(int k)
    {
        int sum = 0, cur = 0;
        while(sum + cur <= k)
        {
            sum += cur;
            cur++;
        }
        return cur - 1;
    }


    void c() throws Exception
    {
        String[] str = split();
        long a = Long.valueOf(str[0]);
        String part2 = "" + str[1].charAt(0) + str[1].charAt(2) + str[1].charAt(3);
        int b = Integer.valueOf(part2);
        long prod = a * b;
        prod /= 100;
        System.out.println(prod);
    }

    int gcd(int a, int b)
    {
        if(b == 0) return a;
         return gcd(b, a % b);
    }

    void b() throws Exception
    {
        int n = readInt();
        BigInteger prod = BigInteger.ONE,
                    cap = new BigInteger("10");
        cap = cap.pow(18);
        String[] split = split();
        
        for(int i = 0; i < n; i++)
        {
            prod = prod.multiply(new BigInteger(split[i]));
        }    
        if(prod.compareTo(cap) <= 0) System.out.println(prod);
        else System.out.println(-1);
        
    }

    void a() throws Exception
    {
        int[] ary = toIntArray();
        System.out.println(ary[0] * ary[1]);
    }
}
