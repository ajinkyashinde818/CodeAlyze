import java.util.*;
import java.io.*;

class Main {

	void solve() {
		
		int k = inint(), s = inint();
		int count = 0;
		
		for (int x=0; x<=k; x++) {
			for (int y=0; y<=k; y++) {
				int z = s - x - y;
				if ((0 <= z && z <= k) && x + y + z == s) count++;
			}
		}
		
		out.println(count);

	}

	public static Scanner in = new Scanner(System.in);
	public static PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		new Main().solve();
		out.flush();
	}

	public int inint() {
		return in.nextInt();
	}

	public long inlong() {
		return in.nextLong();
	}

	public String instr() {
		return in.next();
	}

	public char inchar() {
		return in.next().charAt(0);
	}

	public int[] inintar(int num) {
		int[] a = new int[num];
		for (int i=0; i<num; i++) {
			a[i] = in.nextInt();
		}
		return a;
	}

	public char[] incharar() {
		return in.next().toCharArray();
	}

}
