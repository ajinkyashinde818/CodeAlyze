import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn=new Scanner(System.in);
		long n=scn.nextLong();
//		if(n==1){
//			System.out.println(0);
//			return;
//		}
		long val = n;
		long count=0;
		long valx= (long)Math.sqrt(n);
		for(long i=2;i*i<=val;i++){
			//int j=1;
			long val2=i;
			while(n%val2==0 && n>0){
		//	System.out.println(val2+"A"+n);
				n/=val2;
				val2*=i;
				count++;
				
			}
			while(n%i==0){
				n/=i;
			}
			if(n==0){
				break;
			}
		}
		//boolean ch=isprime(n);
		//System.out.println(n);
		count+=n>valx?1:0;
		System.out.println(count);

	}
//	public static boolean isprime(long n){
//		for(int i=2;i*i<=n;i++){
//			if(n%i==0){
//				return false;
//			}
//		}
//	}

}
