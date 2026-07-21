import java.util.*;
import java.io.*;

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

//......................................@uthor_Alx..............................................
//Atlanta       83 71  8  0 1 6 1
//Atlanta       83 71  8  0 1 6 1
   public static void main(String[] args) throws  IOException{
	        		  assign();
	        		  int[] n1=int_arr();
	        		  int n=n1[0],m=n1[1],x=n1[2];//,k=n1[3];
	        		 // int[] arr=int_arr();

	        		 int res=100000000;
	        		 int[][] d=new int[n][m+1];
	        		 for(int i=0;i<n;i++){d[i]=int_arr();}
	        		 for(int i=0;i<1<<n;i++){
	        		 	int[] tmp=new int[m];
	        		 	int tc=0;
	        		 	for(int j=0;j<12;j++){
	        		 		if((i&1<<j)!=0){
	        		 			tc+=d[j][0];
	        		 			for(int k=0;k<m;k++){
	        		 				tmp[k]+=d[j][k+1];
	        		 			}
	        		 		}
	        		 	}
	        		 	boolean bb=true;
	        		 	for(int k=0;k<m;k++){
	        		 		if(tmp[k]<x){bb=false;break;}
	        		 	}
	        		 	if(bb){res=Math.min(res,tc);}
	        		 	else{continue;}
	        		 }
	        		 if(res==100000000){out.write("-1");}
	        		 else{out.write(res+"");}
	        		  
	        		  
	        	
                      out.flush();
	        		 
	}
}
