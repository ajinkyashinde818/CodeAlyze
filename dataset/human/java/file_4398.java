import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Main {
	 static class FastReader 
	    { 
	        BufferedReader br; 
	        StringTokenizer st; 
	       
	  
	        public FastReader() 
	        { 
	            br = new BufferedReader(new
	                     InputStreamReader(System.in)); 
	        } 
	  
	        String next() 
	        { 
	            while (st == null || !st.hasMoreTokens()) 
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

			public Character charAt(int i) {
				// TODO Auto-generated method stub
				return null;
			} 
	    } 
	
	public static void main(String[] args)throws IOException  {
		FastReader s=new FastReader();		
		int n = s.nextInt();
		int a[] = new int[50];
		int b[] = new int[50];
		int c[] = new int[n];
		for(int i=1;i<=n;i++) {
			a[i]=s.nextInt();
			
		}
		for(int i=1;i<=n;i++) {
			b[i]=s.nextInt();
		
		}
		for(int i=1;i<=n-1;i++) {
			c[i]=s.nextInt();
			
		}
		int c1=0,j=0;
		for(int i=1;i<=n;i++) {
			c1+=b[a[i]];
			
			if(a[i]-j==1) {
				
				c1+=c[a[i]-1];
				
			}
			j=a[i];
		}
		System.out.println(c1);
	}
}
