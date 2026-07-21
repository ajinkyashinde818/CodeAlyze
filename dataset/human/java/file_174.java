import java.util.*;
import static java.lang.System.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		D(sc);
	}
	
	public static void A(Scanner sc) {
		int a = sc.nextInt();
		int b = sc.nextInt();
		int t = sc.nextInt();
		int ret = ((int)(t+0.5)/a)*b;
		out.println(ret);
	}
	
	public static void B(Scanner sc) {
		int max = Integer.MIN_VALUE;
		int sum = 0;
		int N = sc.nextInt();
		int[] subs = new int[N];
		for(int i=0;i<N;i++) {
			subs[i] = sc.nextInt();
 		}
		for(int i=0;i<N;i++) {
			subs[i] -= sc.nextInt();
			if(subs[i]>0) sum+=subs[i];
		}
		out.println(sum);
		
	}
	
	public static void D(Scanner sc) {
		int N = sc.nextInt();
		int min = Integer.MAX_VALUE;
		int count=0;
		long sum = 0;
		for(int i=0;i<N;i++) {
			int n = sc.nextInt();
			if(n<0) count++;
			if(Math.abs(n)<min) min = Math.abs(n);
			sum += Math.abs(n);
		}
		if(count%2==1) sum-=min*2;
		out.println(sum);
	}
}
