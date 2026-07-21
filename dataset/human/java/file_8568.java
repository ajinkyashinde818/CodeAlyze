import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		
		int countA = 0;
		int countB = 0;
		int[] Ayaku = new int[A + 1];
		int[] Byaku = new int[B + 1];
		int[] yaku = new int[A + 1];
		
		for(int i = 1; i <= A; i++) {
			if(A % i == 0) {
				countA++;
				Ayaku[countA] = i;
			}
		}
		
		for(int i = 1; i <= B; i++) {
			if(B % i == 0) {
				countB++;
				Byaku[countB] = i;
			}
		}
		int countK = 0;
		for(int i = 1; i <= countA; i++) {
			for(int j = 1; j <= countB; j++) {
				if(Ayaku[i] == Byaku[j]) {
					countK++;
					yaku[countK] = Ayaku[i];
				}
			}
		}
		System.out.println(yaku[countK + 1 - K]);
	}
}
