import java.util.*;
import java.io.*;

// This file is a "Hello, world!" in Java language by OpenJDK for wandbox.

class Main
{
    public static void main(String[] args)
    {
        new Main().run();
    }
	
	final long MOD=(long)(1e9+7);

	long pow(long a,long n){
		long ret=1;
		for(;n>0;n>>=1,a=a*a%MOD)if(n%2==1)ret=ret*a%MOD;
		return ret;
	}
	
	long inv(long a){
		return a==0?1:pow(a,MOD-2);
	}
	
	int MAX=(int)(3e5);
	long[] fac=new long[MAX];
	{
		fac[0]=fac[1]=1;
		for(int i=2;i<fac.length;++i)fac[i]=fac[i-1]*i%MOD;
	}
	
	void run(){
        Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		long[] x=new long[N];
		for(int i=0;i<N;++i)x[i]=sc.nextLong();
		long cur=0;
		long ans=0;
		for(int i=0;i<N-1;++i){
			cur+=fac[N-1]*inv(i+1)%MOD;
			cur%=MOD;
			ans+=cur*(x[i+1]-x[i])%MOD;
			ans%=MOD;
		}
		System.out.println(ans);
    }
	
	void tr(Object...o){
		System.out.println(Arrays.deepToString(o));
	}
}
// OpenJDK reference:
//   http://openjdk.java.net/

// Java language references:
//   http://docs.oracle.com/javase
