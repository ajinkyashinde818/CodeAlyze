import java.util.*;
import java.io.*;

public class Main{

static BufferedReader s1;
static BufferedWriter out;
static String read() throws IOException{String line="";while(line.length()==0){line=s1.readLine();continue;}return line;}
static int int_v (String s1){return Integer.parseInt(s1);}
static long long_v(String s1){return Long.parseLong(s1);}
static int[] int_arr() throws IOException{String[] a=read().split("\\s+");int[] b=new int[a.length];for(int i=0;i<a.length;i++){b[i]=int_v(a[i]);}return b;}
static long[] long_arr() throws IOException{String[] a=read().split("\\s+");long[] b=new long[a.length];for(int i=0;i<a.length;i++){b[i]=long_v(a[i]);}return b;}
static void assign(){s1=new BufferedReader(new InputStreamReader(System.in));out=new BufferedWriter(new OutputStreamWriter(System.out));}
static long Modpow(long a,long p,long m){long res=1;while(p>0){if((p&1)!=0){res=(res*a)%m;}p >>=1;a=(a*a)%m;}return res;}
//......................................@uthor_Alx..............................................
static long mod=(long)1e9+7;

public static void main(String[] args) throws  IOException{
                assign();
                long n=long_v(read()),n1=n;
                int res=0;
                for(int i=2;(long)i*i<=n;i++){
                    if(n%i!=0) continue;
                    int c=0;
                    while(n1%i==0){c++;n1/=i;}
                    double k=(double)Math.sqrt(1+8*c);k-=1d;
                    k/=2d;k=(int)Math.floor(k);
                    res+=k;
                }
                if(n1>1) res++;
                out.write(res+"");
                out.flush();

    }
}
