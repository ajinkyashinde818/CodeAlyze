import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		String[] A = new String[N];
		String[] B = new String[M];

		for(int i = 0; i < N; i++) {
			A[i] = sc.next();
		}
		for(int i = 0; i < M; i++) {
			B[i] = sc.next();
		}

		String result = Serch(N,M,A,B);
		System.out.println(result);
	}

	private static String Serch(int N,int M,String[] A,String[] B) {
		int count = 0;
		for(int i = 0; i <= N-M; i++) {
			for(int j = 0; j <= N-M; j++) {
				for(int k = 0; k < M; k++) {
					if(A[i+k].substring(j,j+M).equals(B[k].substring(0))) {
						count++;
					}else {
						count = 0;
						break;
					}
					if(count == M) {
						return "Yes";
					}
				}
			}
		}
		return "No";
	}
}
