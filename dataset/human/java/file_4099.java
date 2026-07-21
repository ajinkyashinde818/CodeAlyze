import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
	//try{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        OutputStream outputStream = System.out;
    	PrintWriter out = new PrintWriter(outputStream);

        int i, n, m, k;

		n = Integer.parseInt(br.readLine());
      	int[] a = new int[n+1];
      	int[] b = new int[n+1];
      	int[] c = new int[n];
      StringTokenizer st = new StringTokenizer(br.readLine());
      for(i=1;i<=n;i++)
      	a[i]=Integer.parseInt(st.nextToken());
      st = new StringTokenizer(br.readLine());
      for(i=1;i<=n;i++)
      	b[i]=Integer.parseInt(st.nextToken());
      st = new StringTokenizer(br.readLine());
      for(i=1;i<n;i++)
      	c[i]=Integer.parseInt(st.nextToken());
	
      long sum=0;
      for(i=1;i<=n;i++)
      {
        sum+=b[a[i]];
        
        if(i-1>=0 && a[i-1]+1==a[i])
          	sum+=c[a[i-1]];
      }
      out.print(sum);
	out.flush();
	out.close();
	//}catch(Exception e){}
	}
}
