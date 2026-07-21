import java.util.*;
import java.io.*;
import java.math.BigInteger; 

 public class Main{
// taking inputs
static BufferedReader s1;
static BufferedWriter out;
static String read() throws IOException{String line="";while(line.length()==0){line=s1.readLine();continue;}return line;}
static int int_v (String s1){return Integer.parseInt(s1);}
static long long_v(String s1){return Long.parseLong(s1);}
static int[] int_arr() throws IOException{String[] a=read().split(" ");int[] b=new int[a.length];for(int i=0;i<a.length;i++){b[i]=int_v(a[i]);}return b;}
static long[] long_arr() throws IOException{String[] a=read().split(" ");long[] b=new long[a.length];for(int i=0;i<a.length;i++){b[i]=long_v(a[i]);}return b;}
static void assign(){s1=new BufferedReader(new InputStreamReader(System.in));out=new BufferedWriter(new OutputStreamWriter(System.out));}
// ends

//......................................@uthor_Alx..............................................


//  (Binary lifting)LCS implementation <O(NlogN,logN)>...<preprocessing,query>
//static int l,time;
//static int[][] f; // f[n][l]..
//static int[] tin, tout;
//static List<Integer>[] adj;
/*	return tin[u]<=tin[v]&&tout[u]>=tout[v]; 
}
static void dfs(int u, int p){
	tin[u]=time++;
	f[u][0]=p;
	for(int i=1;i<=l;i++){
		f[u][i]= f[f[u][i-1]][i-1];
	}

	for(int v: adj[u]){
		if(v!=p) dfs(v,u);
	}
	tout[u]=time++;
}
static int lca(int u, int v){
	if(ok(u,v)){return u;}
	if(ok(v,u)){return v;}

	for(int i=l;i>=0;i--){
		if(!ok(f[u][i],v)){
			u=f[u][i];
		}
	}
	return f[u][0];
}*/

public static void main(String[] args) throws  IOException{
	        		  assign();
              int[] arr1=int_arr();
              int k=arr1[0],n=arr1[1];
              int[] arr=int_arr();
              int max=0;
              for(int i=1;i<n;i++){
              	max=Math.max(max,Math.abs(arr[i]-arr[i-1]));
              }
              int x=k-arr[n-1]+arr[0];
              max=Math.max(max,x);
              out.write(k-max+"");
              out.flush();
	        		 
	        	}
	       
	          
	        }
