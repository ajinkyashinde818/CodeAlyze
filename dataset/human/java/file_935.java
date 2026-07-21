import java.util.Scanner;
 
public class Main {

	public static final MyScanner in = new MyScanner();
	public static int[][][][] memo;

	public static void main(String[] args) {

		int N = in.nextInt();
		int R = in.nextInt();
		int a = N >= 10 ? 0 : 100 * (10 - N);
		System.out.println(R+a);

	}


	public static class MyScanner{
		Scanner sc = new Scanner(System.in);
		String nextLine() {return sc.nextLine();}
		String next() {return sc.next();}
		int nextInt() {return Integer.valueOf(sc.next());}
		long nextLong() { return Long.valueOf(sc.next());}
	}
}
