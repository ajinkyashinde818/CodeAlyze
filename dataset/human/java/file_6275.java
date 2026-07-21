import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Map;
import java.util.HashMap;

public class Main
{
    int k, s;
    
    public static void main(String args[])
    {
	new Main().solve();
    }
    
    void solve()
    {
	in();

	int cnt = 0;
	
	for(int i = 0; i <= k; i++) {
	    for(int j = 0; j <= k; j++) {
		int n = s - i - j;
		if(n >= 0 && n <= k) cnt++;
	    }
	}
	
	out(cnt);
    }

    void in()
    {
	Scanner sc = new Scanner(System.in);
	k = sc.nextInt();
	s = sc.nextInt();
    }

    void out()
    {
	
    }
    
    void out(int n)
    {
	System.out.println(n);
    }

    void out(char c)
    {
	System.out.print(c);
    }
    
    void out(String s)
    {
	System.out.println(s);
    }
}
