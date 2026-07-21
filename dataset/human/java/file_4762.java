import java.util.*;

public class Main{
	static private Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args){
		long n = sc.nextLong();
		
		if(n % 2 == 1){
			System.out.println(0);
			return;
		}
		
		long ans = 0;
		for(long num = 10; num <= n; num *= 5){
			ans += n / num;
		}
		
		System.out.println(ans);
	}
}
