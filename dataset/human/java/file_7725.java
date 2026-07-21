import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		long K = sc.nextLong();
		
		int[] A = new int[N];
		for(int i=0; i<N; i++)
			A[i] = sc.nextInt()-1;
		
		int[] p = new int[N];
		int cur = 0;
		p[cur] = 1;
		while(true) {
			int next = A[cur];
			if(p[next]==0) {
				p[next] = p[cur]+1;
				cur = next;
			} else {
				int v1 = p[next]-1;
				int v2 = p[cur]+1-p[next];
				if(K > v1+v2) {
					K = v1 + (K-v1)%v2;
				}
				break;
			}
		}
		
		cur = 0;
		while(K>0) {
			cur = A[cur];
			K--;
		}
		
		System.out.println(cur+1);
		sc.close();
	}
}
