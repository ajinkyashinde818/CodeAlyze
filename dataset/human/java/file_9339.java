import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.*;
public class Main {
	
	
	
	public static void main(String[] args) {
		
		FastScanner fs = new FastScanner();
		int n = fs.nextInt();
		int d[][]=new int[n][2];
		int c=0;
		int flag=0;
		for(int i=0;i<n;i++)
		{
			d[i][0]=fs.nextInt();
			d[i][1]=fs.nextInt();
			if(d[i][0]==d[i][1])
				{
					c++;
					if(c==3)
						flag=1;
				}
			else
			{
				if(c==3)
					{
						flag=1;
					}
				else
					c=0;
			}
			
		}
		if(flag==1)
			System.out.println("Yes");
		else
			System.out.println("No");
	}
	
	
	
	static class FastScanner 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastScanner() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    }
	
	

}
