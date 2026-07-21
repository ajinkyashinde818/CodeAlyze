import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String lines = sc.nextLine();
		String[] line = lines.split(" ");
		int K = Integer.parseInt(line[0]);
		int N = Integer.parseInt(line[1]);

		lines = sc.nextLine();
		line = lines.split(" ");
		int[] A = new int[N];
		int distance = -1;

		for(int i = 0; i < A.length; i++) {
			A[i] = Integer.parseInt(line[i]);
		}

		int sum = 0;
		int Max = -1;
		for(int i = 0; i < N-1; i++) {
			distance = A[i+1] - A[i];
			if(Max < distance) {
				Max = distance;
			}else {

			}
		}
		distance = K - (A[N-1] - A[0]);
		if(Max < distance) {
			Max = distance;
		}

		System.out.println(K - Max);

	}
}
