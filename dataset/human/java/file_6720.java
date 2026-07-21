import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in); 
		int P = input.nextInt();
		int N = input.nextInt();
		int[] houses = new int[N];
		for (int i = 0; i < N; i++) {
			houses[i] = input.nextInt();
		}
		int MAX = 0;
		for (int i = 0; i < N-1; i++) {
			MAX=Math.max(MAX, houses[i+1]-houses[i]);
		}
		System.out.println(Math.min(P-MAX,houses[N-1]-houses[0]));
	}
}
