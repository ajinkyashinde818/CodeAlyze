import java.util.*;
import java.io.*;
public class Main{
/// functions
static long gcd(long a,long b){if(b==0){return a;}return gcd(b,a%b);}
static long Modpow(long a,long p,long m){long res=1;while(p>0){if((p&1)!=0){res=(res*a)%m;}p >>=1;a=(a*a)%m;}return res;}
static long Modmul(long a,long b,long m){return ((a%m)*(b%m))%m;}
static long ModInv(long a,long m){return Modpow(a,m-2,m);}
static long nck(int n,int r,long m){if(r>n){return 0l;}return Modmul(f[n],ModInv(Modmul(f[n-r],f[r],m),m),m);}
// end
static long[] f;
// taking inputs
static BufferedReader s;
static BufferedWriter out;
static String read() throws IOException{String line="";while(line.length()==0){line=s.readLine();continue;}return line;}
static int int_v (String s1){return Integer.parseInt(s1);}
static long long_v(String s1){return Long.parseLong(s1);}
static int[] int_arr() throws IOException{String[] a=read().split(" ");int[] b=new int[a.length];for(int i=0;i<a.length;i++){b[i]=int_v(a[i]);}return b;}
static long[] long_arr() throws IOException{String[] a=read().split(" ");long[] b=new long[a.length];for(int i=0;i<a.length;i++){b[i]=long_v(a[i]);}return b;}
static void assign(){s=new BufferedReader(new InputStreamReader(System.in));out=new BufferedWriter(new OutputStreamWriter(System.out));}
// ends
//......................................@uthor_Alx..............................................

public static void main(String[] args) throws  IOException{
       assign();
       String s1=read();
       char[] arr=new char[900000];
       int j1=400000,i1=400000-1;
       for(int i=0;i<s1.length();i++){
       	arr[j1]=s1.charAt(i);
       	j1++;
       }

        int q=int_v(read()); int flag=0;
        while(q--!=0){
        	String[] z=read().split(" ");
        	if(int_v(z[0])==1){
        		flag=(1^flag);
        		//sb=sb.reverse();
        	}
        	else{
        		if(flag==0){
        			if(int_v(z[1])==1){arr[i1]=z[2].charAt(0);i1--;}//sb.insert(0,z[2]);
        		else{arr[j1]=z[2].charAt(0);j1++;}//sb.append(z[2]);
        		}
        		else{
        			if(int_v(z[1])==1){arr[j1]=z[2].charAt(0);j1++;}
        		else{arr[i1]=z[2].charAt(0);i1--;}
        		}
        		
        	}
        }
    if(flag==0){
    	for(int i=i1+1;i<j1;i++){
    		out.write(arr[i]+"");
    	}
    	out.write("\n");
    }
     if(flag==1){
     	for(int i=j1-1;i>i1;i--){
    		out.write(arr[i]+"");
    	}
    	out.write("\n");
     }
             
        out.flush();
  }
}
