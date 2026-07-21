//package atcoder;
 
import java.util.*;
 
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int N = sc.nextInt();
		int A[] = new int [N];
		for(int i=0;i<N;i++) {
			A[i] = sc.nextInt();
		}
		int min = A[N-1]-A[0];
		for(int j=1;j<N;j++) {
			min = Math.min(min, K-A[j]+A[j-1]);
		}
		System.out.println(min);
	}
}
