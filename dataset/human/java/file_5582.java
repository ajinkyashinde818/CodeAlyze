import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int S = sc.nextInt();
		for(int i = 0; i < N; i++) {
			if(i < K)
				System.out.print(S + " ");
			else {
				if(S < 1000000000)
					System.out.print(S+1 + " ");
				else
					System.out.print(1 + " ");
			}
		}
		System.out.println();

	}

}
