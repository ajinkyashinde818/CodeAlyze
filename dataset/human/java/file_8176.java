import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] strArray = br.readLine().split(" ");
		int a = Integer.parseInt(strArray[0]);
		int b = Integer.parseInt(strArray[1]);
		long kobaisu = getKobaisu(a, b);
		System.out.println(kobaisu);
	}
	// 公約数の取得
	  private static long getKoyakusu(long a, long b) {
	    long candidate = a;
	    while (b % a != 0) {
	      candidate = b % a;
	      b = a;
	      a = candidate;
	    }
	    return candidate;
	  }

	  // 公倍数の取得
	  private static long getKobaisu(long a, long b) {
	    return (a * b) / getKoyakusu(a, b);
	  }
}
