import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
 
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
 
		int K = sc.nextInt();
		int N = sc.nextInt();
		List<Integer> A = new ArrayList<>();
 
		for (int i=0; i<N; i++) {
			A.add(sc.nextInt());
		}
		
		Collections.sort(A);
		
		int max = 0;
		for (int i=0; i<N - 1; i++) {
			int kyori = A.get(i + 1) - A.get(i);
			max = Math.max(kyori, max);
		}
		int kyori = A.get(0) + (K - A.get(N - 1));
		max = Math.max(kyori, max);
		
		System.out.println(K - max);
	}
}
