import java.util.*;
import static java.lang.Integer.*;
import static java.lang.Long.*;
import static java.lang.Math.*;
import static java.lang.System.*;

public class Main {
	public static void main(String[] args) {
		int i=0,j=0,k=0;
		Scanner sc = new Scanner(in);
		int n = parseInt(sc.next());
		long[] aa = new long[n];
		aa[0] = parseLong(sc.next());
		for(i=1;i<n;i++) {
			aa[i]=aa[i-1]+parseLong(sc.next());
		}
		sc.close();
		long mn = 1000000000L*200000L;
		long tmp = 0L;
		for (i = 0; i < n-1; i++) {
			tmp = abs(aa[n-1] - aa[i]*2);
			if(mn>tmp) mn=tmp;
		}
		out.println(mn);
	}
}
