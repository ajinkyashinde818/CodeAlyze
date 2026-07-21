import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		String s=sc.next();
		int count=0;
		long ans=1;
		long mod=1000000007;
		for(int i=0; i<2*n; i++){
			if(i==0 || i==2*n-1){
				if(s.charAt(i)=='W'){
					System.out.println(0);
					return;
				}
				if(i==0){
					count++;
				}else{
					count--;
				}
			}else if(s.charAt(i)=='B'){
				if(count%2==0){
					count++;
				}else{
					ans=(ans*count)%mod;
					count--;
				}
			}else{
				if(count%2==0){
					ans=(ans*count)%mod;
					count--;
				}else{
					count++;
				}
			}
			if(count<0){
				System.out.println(0);
				return;
			}
		}
		if(count!=0){
			System.out.println(0);
			return;
		}
		for(int i=2; i<=n; i++){
			ans=(ans*i)%mod;
		}
		System.out.println(ans);
	}
}
