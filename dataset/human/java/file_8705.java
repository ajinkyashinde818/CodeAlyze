import java.util.ArrayList;
import java.util.Scanner;

public class Main {
 	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();

		ArrayList<Integer> list = new ArrayList<>();

		for (int i = 1; i <= A; i++) {
			if (A % i==0) {
				if (B%i == 0) {
					list.add(i);
				}
			}
		}
		System.out.println(list.get(list.size() -K));
 	}
}
