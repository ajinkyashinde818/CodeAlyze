import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		sc.close();
		System.out.println(lcm(n,a));
	}

	public static int arrayMax(int[] array) {
		int ans = Integer.MIN_VALUE;
		for (int i = 0; i < array.length; i++) {
			if (array[i] > ans)
				ans = array[i];
		}
		return ans;
	}

	public static long arrayMax(long[] array) {
		long ans = Long.MIN_VALUE;
		for (int i = 0; i < array.length; i++) {
			if (array[i] > ans)
				ans = array[i];
		}
		return ans;
	}

	public static int[] arrayInt(Scanner sc, int n) {
		int[] array = new int[n];
		for (int i = 0; i < n; i++) {
			array[i] = sc.nextInt();
		}
		return array;
	}

	public static long[] arrayLong(Scanner sc, int n) {
		long[] array = new long[n];
		for (int i = 0; i < n; i++) {
			array[i] = sc.nextLong();
		}
		return array;
	}

	public static double[] arrayDouble(Scanner sc, int n) {
		double[] array = new double[n];
		for (int i = 0; i < n; i++) {
			array[i] = sc.nextDouble();
		}
		return array;
	}

	public static String[] arrayString(Scanner sc, int n) {
		String[] array = new String[n];
		for (int i = 0; i < n; i++) {
			array[i] = sc.next();
		}
		return array;
	}
	static String nextPermutation (String s) {

	ArrayList<Character> list = new ArrayList<>();
	for (int i=0; i<s.length(); i++) list.add(s.charAt(i));

	int pivotPos = -1;
	char pivot = 0;
	for (int i=list.size()-2; i>=0; i--) {
		if (list.get(i) < list.get(i+1)) {
			pivotPos = i;
			pivot = list.get(i);
			break;
		}
	}

	if (pivotPos==-1 && pivot==0) return "Final";

	int L = pivotPos+1, R = list.size()-1;
	int minPos = -1;
	char min = Character.MAX_VALUE;
	for (int i=R; i>=L; i--) {
		if (pivot < list.get(i)) {
			if (list.get(i) < min) {
				min = list.get(i);
				minPos = i;
			}
		}
	}

	Collections.swap(list, pivotPos, minPos);
	Collections.sort(list.subList(L, R+1));

	StringBuilder sb = new StringBuilder();
	for (int i=0; i<list.size(); i++) sb.append(list.get(i));

	return sb.toString();
}

			public static long gcd(final long[] param) {
			final int len = param.length;
			long g = gcd(param[0], param[1]);
			for (int i = 1; i < len - 1; i++) {
			g = gcd(g, param[i + 1]);
			}
			return g;
			}
			
			public static long gcd(long a, long b) {
			// a > b にする(swap)
			if (a < b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
			}
			// ユークリッドの互除法
			long r = -1;
			while (r != 0) {
			r = a % b;
			a = b;
			b = r;
			}
			
			return a; // b には r=0 の値が入るため、a を返す
			}
			
			
			public static long lcm(long m, long n) {
			return m * n / gcd(m, n);
			}
}
