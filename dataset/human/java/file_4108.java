import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.nextLine());
		int[] buffets = new int[n];
		int[] score = new int[n];
		int[] bonus = new int[n - 1];
		for(int i = 0; i < n; i++) {
			buffets[i] = Integer.parseInt(sc.next());
		}
		for(int i = 0; i < n; i++) {
			score[i] = Integer.parseInt(sc.next());
		}
		for(int i = 0; i < n - 1; i++) {
			bonus[i] = Integer.parseInt(sc.next());
		}
		System.out.println(new Main().buffet(n, buffets, score, bonus));
		sc.close();
	}
	
	public int buffet(int n, int[] buffets, int[] score, int[] bonus) {
		int prev_buffet = -1;
		int sum = 0;
		for(int i = 0; i < n; i++) {
			sum += score[buffets[i] - 1];
			if(prev_buffet + 1 == buffets[i]) {
				sum += bonus[prev_buffet - 1];
			}
			prev_buffet = buffets[i];
		}
		return sum;
	}
}
