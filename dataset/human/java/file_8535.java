import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int k = Integer.parseInt(sc.next());
		sc.close();
		List<Integer> list = new ArrayList<>();
		for(int i=Math.min(a, b);i>0;i--) {
			if(a%i==0&&b%i==0)list.add(i);
		}
		System.out.println(list.get(k-1));
	}
}
