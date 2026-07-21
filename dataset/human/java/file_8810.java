import java.util.*;

public class Main{
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(System.in);
		int A = s.nextInt(), B = s.nextInt(), K = s.nextInt(), k = 0, i = A;
		while (B > 0){
			int C = Math.min(A, B);
			B = Math.max(A, B) % C;
			A = C;
		}
		for (i = A;; i--){
			if (A % i == 0){
				k++;
			}
			if (k == K){
				System.out.println(i);
				break;
			}
		}
		
	}
}
