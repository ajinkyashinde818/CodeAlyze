import java.util.*;
import java.io.PrintWriter;
import static java.lang.Integer.*;
import static java.lang.Long.*;
import static java.lang.Math.*;
import static java.lang.System.*;

public class Main {
	public static final int MOD = 1000000007;
	public static void main(String[] args) {
		int i,j;
		Scanner sc = new Scanner(in);
		long n = parseLong(sc.next());
		sc.close();
		ArrayList<Long> pri = new ArrayList<>();
		pri.add(2L);
		for(long k=3; k*k<=n; k+=2) {
			boolean f=true;
			for (Long l : pri) {
				if(l*l>k) {
					break;
				}
				if(k%l==0) {
					f=false;
					break;
				}
			}
			if(f) {
				pri.add(k);
			}
		}
//		out.println(pri.toString());
		long ans=0;
		for (Long l : pri) {
			long cnt=0;
			while(n%l==0) {
				n/=l;
				cnt++;
			}
			if(cnt>0) {
//				out.printf("%d:%d:%d%n", l, cnt, (long)((1+Math.sqrt(1+4*cnt))/2));
				ans+=(long)((-1+Math.sqrt(1+8*cnt))/2);
			}
			if(n==1) break;
		}
//		out.println(n);
		if(n>1) ans++;
		out.println(ans);
	}
}
