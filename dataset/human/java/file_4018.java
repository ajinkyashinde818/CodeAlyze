import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// Nの入力
		int N = sc.nextInt();
		
		// Aiの入力
		ArrayList<Integer> a = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			a.add(sc.nextInt());
		}
		
		// Biは最初に全部合計しておく
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += sc.nextInt();
		}

		// Ciの入力
		ArrayList<Integer> c = new ArrayList<>();
		for (int i = 0; i < N-1; i++) {
			c.add(sc.nextInt());
		}
		
		// Cの満足度を加算
		for (int i = 0; i < N-1; i++) {
			if (a.get(i) + 1 == a.get(i+1)) {
				sum += c.get(a.get(i)-1);
			}
		}
		
		// 結果の出力
		System.out.println(sum);
		
		sc.close();
	}
}
