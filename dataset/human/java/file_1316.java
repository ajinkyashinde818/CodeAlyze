import java.util.Scanner;

class Main{
	static boolean check(String[] A, String[] B) {
		for(int i = 0; i + B.length <= A.length; i++) {
			for(int j = 0; j + B.length <= A.length; j++) {
				//matching
				int matchedline = 0;
				for(int k = 0; k < B.length; k++) {
					if(B[k].equals(A[k + i].substring(j, j + B.length))) {
						matchedline++;
					}
				}
				if(matchedline == B.length) return true;;
			}
		}
		return false;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), M = sc.nextInt();
		String[] A = new String[N];
		String[] B = new String[M];
		for(int i = 0; i < N; i++) A[i] = sc.next();
		for(int i = 0; i < M; i++) B[i] = sc.next();
		System.out.println(check(A, B) ? "Yes" : "No");
	}
}
