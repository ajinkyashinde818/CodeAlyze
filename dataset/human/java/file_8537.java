import java.util.*;

public class Main {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		
		int k = 0;
		for (int i = Math.min(A, B); i > 0; i--) {
			if (A%i == 0 && B%i == 0) {
				k++;
				if (k == C) {
					System.out.println(i);
				}
			}
		}
    }
  
}
