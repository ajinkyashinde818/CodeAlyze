import java.io.*;
import java.util.*;

public class Main
{
    PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer tok;

    int MOD = 1000000007;

    public void go() throws IOException
    {
        long[] fact = new long[100005];
        fact[0] = 1;
        for (int i = 1; i < fact.length; i++)
        {
            fact[i] = i * fact[i-1] % MOD;
        }
        ntok();
        int n = ipar();
        ntok();
        char[] line = spar().toCharArray();
        if (possible(line, 0, 0))
        {
            int c = 0;
            long ans = 1;
            for (int i = 0; i < 2*n; i++)
            {
                if (line[i] == '(')
                {
                    c++;
                }
                else
                {
                    ans *= c;
                    ans %= MOD;
                    c--;
                }
            }
            out.println(ans * fact[n] % MOD);
        }
        else
        {
            out.println(0);
        }

        out.flush();
        in.close();
    }

    public long inverse(long n)
    {
        return modPow(n, MOD-2);
    }

    public long modPow(long n, int p)
    {
        if (p == 0)
        {
            return 1;
        }
        long pow = modPow(n*n%MOD, p/2);
        if (p%2 == 1)
        {
            pow *= n;
            pow %= MOD;
        }
        return pow;
    }

    public boolean possible(char[] line, int i, int c)
    {
        if (c < 0)
        {
            return false;
        }
        if (i == line.length)
        {
            return c == 0;
        }
        if (c % 2 == 0)
        {
            if (line[i] == 'B')
            {
                line[i] = '(';
                return possible(line, i+1, c+1);
            }
            else
            {
                line[i] = ')';
                return possible(line, i+1, c-1);
            }
        }
        else
        {
            if (line[i] == 'W')
            {
                line[i] = '(';
                return possible(line, i+1, c+1);
            }
            else
            {
                line[i] = ')';
                return possible(line, i+1, c-1);
            }
        }
    }

    public void ntok() throws IOException
    {
        tok = new StringTokenizer(in.readLine());
    }

    public int ipar()
    {
        return Integer.parseInt(tok.nextToken());
    }

    public long lpar()
    {
        return Long.parseLong(tok.nextToken());
    }

    public double dpar()
    {
        return Double.parseDouble(tok.nextToken());
    }

    public String spar()
    {
        return tok.nextToken();
    }

    public static void main(String[] args) throws IOException
    {
        new Main().go();
    }
}
