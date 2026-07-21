// practice with kaiboy
import java.io.*;
import java.util.*;

public class Main extends PrintWriter {
	Main() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		Main o = new Main(); o.main(); o.flush();
	}

	long count(long n) {
		return n < 5 ? 0 : count(n / 5) + n / 5;
	}
	void main() {
		long n = sc.nextLong();
		println(n % 2 == 1 ? 0 : count(n / 2));
	}
}
