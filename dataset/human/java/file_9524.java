import java.io.*;
import java.math.*;
import java.util.*;
import java.lang.*;

// import java.text.DecimalFormat; 
// import java.text.DecimalFormatSymbols; 
/*
 
 
 
 */

public class Main {

    public static void main(String args[] ) throws Exception {
        PrintWriter pw=new PrintWriter(System.out);
        FastScanner sc = new FastScanner();
        
        int t=1;
        //t = sc.ni();
        while(t-->0) {
        	solve(pw,sc);
        }
       
        pw.close();
    }
   
    private static void solve(PrintWriter pw, FastScanner sc) {
    	int n = sc.ni();
    	int co = 0;
    	int max= 0;
    	while(n-->0){
    		int d1 = sc.ni(),d2 = sc.ni();
    		if(d1==d2) {
    			co++;
    		} else 
    			co=0;
    		max = Math.max(max, co);
    	}
    	if(max>=3)
    		pw.print("Yes");
    	else 
    		pw.print("No");
    	
	}
   

	static <T> void deb(T x,int o){
       System.out.print(x);
       if(o==0) {
    	   System.out.println();
    	   
       }
    }
   
   
   static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String ne() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		public String ne(int k) {
			try {
				return br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return "Not able to read";
		}
		
		int ni() {
			return Integer.parseInt(ne());
		}
		
		long nl() {
			return Long.parseLong(ne());
		}
		
		double nd() {
			return Double.parseDouble(ne());
		}
		
	    
	}
   
}
