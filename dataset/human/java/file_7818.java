import java.util.*;
import java.io.*;
public class Main{
   public static void main(String[] args) throws  IOException{
	        		  assign();
	        		  	long[] n1=long_arr();
	        		  	int n=(int)n1[0];long k=n1[1];
	        		  	int[] a=int_arr();
	        		  	int[][] dp=new int[n+1][64];
	        		  	for(int i=1;i<=n;i++){
	        		  		dp[i][0]=a[i-1];
	        		  	}
	        		  	for(int j=1;j<64;j++){
	        		  		for(int i=1;i<=n;i++){
	        		  			dp[i][j]=dp[dp[i][j-1]][j-1];
	        		  		}
	        		  	}
	        		  	int cc=1;
	        		  	for(int i=0;i<64;i++){
	        		  		if((k&1l<<i)!=0){
	        		  			cc=dp[cc][i];
	        		  		}
	        		  	}
		  	        	out.write(cc+"");
	
                      out.flush();		 
	}
  
static BufferedReader s1;
static BufferedWriter out;
static String read() throws IOException{String line="";while(line.length()==0){line=s1.readLine();continue;}return line;}
static int int_v (String s1){return Integer.parseInt(s1);}
static long long_v(String s1){return Long.parseLong(s1);}
static int[] int_arr() throws IOException{String[] a=read().split(" ");int[] b=new int[a.length];for(int i=0;i<a.length;i++){b[i]=int_v(a[i]);}return b;}
static long[] long_arr() throws IOException{String[] a=read().split(" ");long[] b=new long[a.length];for(int i=0;i<a.length;i++){b[i]=long_v(a[i]);}return b;}
static void assign(){s1=new BufferedReader(new InputStreamReader(System.in));out=new BufferedWriter(new OutputStreamWriter(System.out));}
}
