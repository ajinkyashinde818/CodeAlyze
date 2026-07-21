import java.util.*;
import java.io.PrintWriter;
import static java.lang.Integer.*;
import static java.lang.Long.*;
import static java.lang.Math.*;
import static java.lang.System.*;

public class Main {
	public static int MOD = 1000000007;
	public static void main(String[] args) {
		int i,j;
		Scanner sc = new Scanner(in);
		long a = parseLong(sc.next());
		long b = parseLong(sc.next());
		sc.close();
		out.println(a*b/gcm(a,b));
	}
	public static long gcm(long a, long b) {
		long tmp;
		while((tmp=a%b)!=0) {
			a=b;
			b=tmp;
		}
		return b;
	}
}
