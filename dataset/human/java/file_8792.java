import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int A = scn.nextInt();
		int B = scn.nextInt();
		int K = scn.nextInt();
		int ans;
		int k = 0;
		for(int i = Math.min(A, B);i > 0;i--) {
			if(A%i==0 && B%i == 0) {
				k++;
				if(k == K) {
					System.out.println(i);
					break;
				}
			}
		}
	}

}
