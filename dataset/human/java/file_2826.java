import java.util.*;
public class Main{
	static long mod=1000000007;
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long ans=0;
		long[] x=new long[n];
		for(int i=0; i<n; i++){
			x[i]=sc.nextLong();
		}
		long fact=1;
		for(int i=2; i<n; i++){
			fact*=i;
			fact%=mod;
		}
		long sum=0;
		for(int i=0; i<n-1; i++){
			sum+=pow(i+1,mod-2);
			sum%=mod;
			ans+=(x[i+1]-x[i])*(sum*fact%mod);
			ans%=mod;
		}
		System.out.println(ans);
	}
	static long pow(long p,long q){
		long res=1;
		while(q>0){
			if((q & 1)==1){
				res*=p;
				res%=mod;
			}
			q>>=1;
			p*=p;
			p%=mod;
		}
		return res;
	}
}
