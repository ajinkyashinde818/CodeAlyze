import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		long n = sc.nextLong(),m=n;
		long ans=0;
		sc.close();
		for(long i=2;i*i<m;i++) {
			long count=0; //iを素因数としていくつ含むか
			while(n%i==0) {
				n/=i;
				count++;
			}
			if(count!=0) {
				long temp=1;
				while(true) {
					count-=temp;
					if(count==0) break;
					if(count<0) {
						temp--;
						break;
					}
					temp++;
				}
				ans+=temp;
			}
		}
		if(n==1) System.out.println(ans);
		else System.out.println(ans+1);
	}
}
