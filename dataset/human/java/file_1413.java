import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.next());
		int M = Integer.parseInt(sc.next());
		String A[] = new String[N];
		for(int i = 0; i < N; i++) {
			A[i] = sc.next();
		}
		String B[] = new String[N];
		for(int i = 0; i < M; i++) {
			B[i] = sc.next();
		}
		
		for(int i = 0; i < N; i++) {
			in : for(int j = 0; j < N; j++) {
				for(int h = 0; h < M; h++) {
					for(int w = 0; w < M; w++) {
						if(j + w >= N) continue in;
						if(i + h >= N) continue in;
						if(!A[i + h].substring(j + w, j + w + 1).equals(B[h].substring(w, w + 1))) continue in;						
					}
				}
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
	}
}
