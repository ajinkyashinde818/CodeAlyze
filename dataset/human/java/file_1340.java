import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Map;
import java.util.HashMap;

public class Main
{
    int n, m;
    String a[] = new String[51];
    String b[] = new String[51];
    
    public static void main(String args[])
    {
	new Main().solve();
    }
    
    void solve()
    {
	in();

	boolean flg = false;
	
	for(int i = 0; i <= n - m; i++) {
	    for(int j = 0; j <= n - m; j++) {

		boolean sflg = true;

		for(int k = 0; k < m; k++) {
		    String line = a[i + k].substring(j, j + m);
		    if(!b[k].equals(line)) sflg = false;
		}

		if(sflg) flg = true;
		
	    }
	}
	
	if(flg) out("Yes");
	else    out("No");
    }

    void in()
    {
	Scanner sc = new Scanner(System.in);
	n = sc.nextInt();
	m = sc.nextInt();
	for(int i = 0; i < n; i++) a[i] = sc.next();
	for(int i = 0; i < m; i++) b[i] = sc.next();
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
