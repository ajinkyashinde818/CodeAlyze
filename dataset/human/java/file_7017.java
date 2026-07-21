import java.util.*;
import java.lang.*;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		int K = sc.nextInt();
		int N = sc.nextInt();
		int[] A = new int[N];
		for( int i=0; i<N; i++ ){
			A[i] = sc.nextInt();
		}
		int[] dis = new int[N];
		int maxium = 0;
		for( int i=0; i<N; i++ ){
			if( i<N-1 ){
				int a = A[i+1]-A[i];
				maxium = Math.max(maxium,a);
			}else{
				int a = A[0]+(K-A[N-1]);
				maxium = Math.max(maxium,a);
			}
		}
		System.out.println(K-maxium);
	}
}
