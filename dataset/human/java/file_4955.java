import java.util.Scanner;
public class Main {
@SuppressWarnings("resource")
public static void main(String[] args) {
	Scanner sc =new Scanner(System.in);
	long N=sc.nextLong();
		System.out.println(num(N));

	}
static long num(long N) {
	if(N==0||N==1||N%2==1) {
		return 0;
	}else {
		long ans=0;
		N/=2;
		while(N>=5) {
			ans+=N/5;
			N/=5;
		}
return ans;
	}
}
}
