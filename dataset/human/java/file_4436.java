import java.io.*;
import java.util.*;

public class Main
{
    PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer tok;

    public void go() throws IOException
    {
        ntok();
        int a = ipar();
        int b = ipar();
        int c = ipar();
        int m1 = Math.min(c, b);
        long total = m1 * 2;
        c -= m1;
        b -= m1;
        int m2 = Math.min(c, a);
        total += m2;
        c -= m2;
        a -= m2;
        total += b;
        total += Math.min(1, c);
        out.println(total);

        out.flush();
        in.close();
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
