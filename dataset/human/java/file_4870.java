import java.util.*;
import java.io.PrintWriter;
import static java.lang.Integer.*;
import static java.lang.Long.*;
import static java.lang.Math.*;
import static java.lang.System.*;

public class Main {
	public static long MOD = 1000000007;
	public static void main(String[] args) {
		int i,j,k;
		Scanner sc = new Scanner(in);
		long n = parseLong(sc.next());
		sc.close();
		long cnt = 0;
		if(n%2==0) {
			long l = 10;
			long tmp=0;
			while((tmp=n/l)>0) {
				cnt+=tmp;
				l*=5;
			}
		}
		out.println(cnt);
	}
}
