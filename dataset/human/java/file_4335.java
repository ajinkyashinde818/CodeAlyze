import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int result = 0;
		ArrayList<Integer> A = new ArrayList<Integer>();
		ArrayList<Integer> B = new ArrayList<Integer>();
		ArrayList<Integer> C = new ArrayList<Integer>();
		for(int i = 0; i < N; i++) {
			A.add(sc.nextInt());
		}
		for(int i = 0; i < N; i++) {
			B.add(sc.nextInt());
		}
		for(int i = 0; i < N - 1; i++) {
			C.add(sc.nextInt());
		}

		int k = 100;
		int l = 100;
		for(int i = 0; i < N; i++) {
			k = A.get(i) - 1;
			result += B.get(k);
			if(k == l) {
				result += C.get(k - 1);
			}
			l = A.get(i);
		}
		System.out.println(result);
		sc.close();
	}
}
