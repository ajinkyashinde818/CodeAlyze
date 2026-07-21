import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		long N = sc.nextLong();
		
		int ans = 0;
		for(long d=2; d*d<=N; d++) {
			if(N%d==0) {
				int count = 0;
				while(N%d==0) {
					count++;
					N/=d;
				}
				for(int i=1; ; i++) {
					count-=i;
					if(count>=0)
						ans++;
					else
						break;
				}
			}
		}
		if(N>1)
			ans++;
		
		System.out.println(ans);
		sc.close();
	}
}
