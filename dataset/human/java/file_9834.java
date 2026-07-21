import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
  public static void main(String[] args) throws IOException
  {
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);
    String s;
    String sl[];

    s = r.readLine();
    sl = s.split(" ");

    int n = Integer.parseInt(sl[0]);
    int m = Integer.parseInt(sl[1]);
    int x = Integer.parseInt(sl[2]);

    int a[][] = new int[12][12];
    int c[] = new int[12];

    // Long.parseLong(sl[0]);

    for(int i = 0; i < n; i++)
    {
        s = r.readLine();
        sl = s.split(" ");
    	c[i] = Integer.parseInt(sl[0]);
    	for(int j = 0; j < m; j++)
    	{
    		a[i][j] = Integer.parseInt(sl[1 + j]);
    	}
    }

    int ans = Integer.MAX_VALUE;
    for(int b = 0; b < 1 << 12; b++)
    {
    	int v = 0;
    	int ss[] = new int[12];
        for(int i = 0; i < n; i++)
        {
        	if(((1 << i) & b) > 0)
        	{
    			v += c[i];
        		for(int j = 0; j < m; j++)
        		{
        			ss[j] += a[i][j];
        		}
        	}
        }
        boolean bb = true;
        for(int i = 0; i < m; i++)
        {
        	if(ss[i] < x) bb = false;
        }
        if(bb) {
        	ans = Math.min(v, ans);
        }
    }

    System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
  }

}
