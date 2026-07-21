import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        ABC073A s = new ABC073A();
        s.read();
        s.solve();
    }
}

class ABC073A
{
    String N;

    void read()
    {
        Scanner in = new Scanner(System.in);
        N = in.nextLine();
    }

    void solve()
    {
        if (N.contains("9"))
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
