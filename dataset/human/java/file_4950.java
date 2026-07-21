import java.util.*;

public class Main{
	public static void main(String[] $){
		Scanner s=new Scanner(System.in);
		long n=s.nextLong();
		if(n%2==1) {
			System.out.println(0);
			return;
		}
		long r=n/=10;
		for(long i=n/5;i>0;i/=5)
			r+=i;
		System.out.println(r);
	}
}
