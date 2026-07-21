import java.util.Scanner;

public class Main {
	static long calcOneCycle(int A[] , int start){
		int cp = start;
		for(int i = 0 ; i < A.length ;  ++i){
			cp = A[cp];
			if(cp == start){
				return i + 1;
			}
		}
		return A.length;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long K = sc.nextLong();
		int A[] = new int[N];
		for(int i = 0 ; i < N ; ++i){
			A[i] = sc.nextInt() - 1;
		}
		boolean vis[] = new boolean[N];
		int cp = 0;
		vis[cp] = true;
		while(K > 0){		
			cp = A[cp];
			K--;
			if(vis[cp]){
				break;
			}
			vis[cp] = true;
		}
		long l = calcOneCycle(A, cp);
//		System.out.println(cp+" "+K+" "+l);
		K = K % l;
//		System.out.println(cp+" "+K+" "+l);
		while(K > 0){		
			cp = A[cp];
			K--;
		}
		System.out.println(cp+1);
	}
}
