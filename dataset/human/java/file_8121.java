import java.util.*;
public class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner (System.in);
		long a=sc.nextLong();
		long b=sc.nextLong();
		long max;
		if (a>=b)max=a;
		else max=b;
		long ans;
		for(ans=max;ans<=a*b;ans+=max) {
			if (ans%a==0&&ans%b==0)break;
		}
		System.out.println(ans);
	}
}
