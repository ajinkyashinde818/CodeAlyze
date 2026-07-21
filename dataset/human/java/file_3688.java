import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

class Main
{
    public static void main(String[] args) throws IOException
    {
        Scanner in = new Scanner(System.in);
        P78ASolver s = new P78ASolver(in, System.out);
        s.read();
        s.solve();
    }
}

class P78ASolver
{
    Scanner in;
    PrintStream out;
    String X, Y;

    public P78ASolver(Scanner s, PrintStream p)
    {
        in = s;
        out = p;
    }

    public void read() throws IOException
    {
        String[] ss = in.nextLine().split(" ");
        X = ss[0];
        Y = ss[1];
    }

    public void solve()
    {
        if (X.compareTo(Y) < 0)
            out.println("<");
        else if (X.compareTo(Y) == 0)
            out.println("=");
        else
            out.println(">");
    }
}
