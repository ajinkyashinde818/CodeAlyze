//
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
        if(test < 0) {String[] str = in.readLine().split(" ");}
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
        // System.out.println((-100 + 0) / 2);

        new Main().d();
        out.flush();
    }
    void f() throws Exception
    {

    }
    void e() throws Exception
    {
        int[] ary = toIntArray();
        int n = ary[0], p = ary[1];

        String str = in.readLine();
        Map<Long, Integer> map = new HashMap<>();

        long sum = 0;
        long ans = 0;
        for(int i = 0;  i < n; i++)
        {
            sum = sum * 10 + (str.charAt(i) - '0');
            sum %= p;
            if(sum == 0) ans++;
            if(map.containsKey(sum)) {
                // System.out.println(map);
                ans += map.get(sum);
            }
            map.put(sum, map.getOrDefault(sum, 0) + 1);            
        }
        // System.out.println(map);
        out.println(ans);
    }

    void d() throws Exception
    {
        String str = in.readLine();
        Stack<Character> front = new Stack<>();
        Queue<Character> back = new LinkedList<>();

        int q = readInt();

        boolean rev = false;
        while(q-- > 0)
        {
            String[] sp = split();
            if(sp[0].equals("1"))
            {
                rev = !rev;
            }
            else
            {
                int f = sp[1].charAt(0) - '0';
                char c = sp[2].charAt(0);
                if(f == 1)
                {
                    // to front if not reversed
                    if(!rev) front.push(c);
                    else back.offer(c);
                }
                else
                {
                    // to end if not reversed
                    if(!rev) back.offer(c);
                    else front.push(c);
                }
            }
        }
        
        StringBuilder sb = new StringBuilder();
        while(!front.isEmpty())
        {
            sb.append(front.pop());
        }
        sb.append(str);
        while(!back.isEmpty())
        {
            sb.append(back.poll());
        }

        String ans = sb.toString();
        if(rev) ans = sb.reverse().toString();
        out.println(ans);

    }

    void c() throws Exception
    {
        int[] ary = toIntArray();
        int a = ary[0], b = ary[1];
        // maxed at 1000
        for(int price = 1; price <= 1000; price++)
        {
            int p1 = (int)(price * 0.08),
                p2 = (int)(price * 0.1);
            if(p1 == a && p2 == b)
            {
                out.println(price);
                return;
            }
        }
        out.println(-1);
    }

    void b() throws Exception
    {
        long[] ary = toLongArray();
        long n = ary[0], a = ary[1], b = ary[2];
        // a blue then b red balls
        // number of blue balls in first N
        long ab = a + b;
        long mult = n / ab;
        long rem = n % ab;
        long ans = mult * a;
        if(rem < a) ans += rem;
        else ans +=a ;
        out.println(ans);
    }

    void a() throws Exception
    {
        String str = in.readLine();
        int a = 0, b = 0;
        for(char c : str.toCharArray())
        {
            if(c == 'A') a++;
            else b++;
        }
        if(a > 0 && b > 0) out.println("Yes");
        else out.println("No");
    }
}
