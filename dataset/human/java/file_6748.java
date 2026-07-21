import java.util.*;
import java.io.PrintWriter;
import static java.lang.Integer.*;
import static java.lang.Long.*;
import static java.lang.Math.*;
import static java.lang.System.*;

public class Main {
	public static final int MOD = 1000000007;
	public static ArrayList<Integer> list = new ArrayList<>();
	public static void main(String[] args) {
		int i,j;
		Scanner sc = new Scanner(in);
		int k = parseInt(sc.next());
		int n = parseInt(sc.next());
		int[] a = new int[n];
		for (i = 0; i < n; i++) {
			a[i] = parseInt(sc.next());
		}
		sc.close();
		int[] d = new int[n];
		for (i = 0; i < n-1; i++) {
			d[i] = a[i+1] - a[i];
		}
		d[n-1] = k +a[0] - a[n-1];
		Arrays.parallelSort(d);
		int sum = 0;
		for (i = 0; i < n-1; i++) {
			sum += d[i];
		}
		out.println(sum);
	}
}
