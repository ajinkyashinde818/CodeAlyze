import java.util.*;
import static java.lang.System.*;
import static java.lang.Integer.*;
import static java.lang.Long.*;
import static java.lang.Math.*;

public class Main {
	public static void main(String[] args) {
		int i;
		Scanner sc = new Scanner(in);
		int n = parseInt(sc.next());
		long[] a = new long[n];
		int mcnt = 0;
		for(i=0; i<n; i++) {
			a[i] = parseLong(sc.next());
			if(a[i]<0) {
				mcnt++;
				a[i]=-a[i];
			}
		}
		sc.close();
		Arrays.parallelSort(a);
		long sum=0;
		for(i=1; i<n; i++) {
			sum+=a[i];
		}
		out.println(mcnt%2==0?sum+a[0]:sum-a[0]);
	}
}
