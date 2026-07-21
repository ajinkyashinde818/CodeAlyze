import java.util.Scanner;
public class Main {
	public static void main(String[] args)throws Exception{
		Scanner stdIn=new Scanner(System.in);
		long N=stdIn.nextLong();
		int ans=0;
		for(long i=2;i<Math.sqrt(N);i+=2){
			if(N%i==0){
				int a=0;
				while(N%i==0){
					N/=i;a++;
				}
				for(int j=1;a>=j;j++){
					a-=j;ans++;
				}
			}
			if(i==2)
				i--;
		}
		if(N!=1)
			ans++;
		System.out.println(ans);
	}
}
