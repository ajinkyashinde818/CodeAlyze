import java.util.*;

public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int N = sc.nextInt();
		int a[] = new int[N + 1];
		for(int i = 0; i < N; i++){
			a[i] = sc.nextInt();
		}
		a[N] = K + a[0];
		
		Arrays.sort(a);
		int max = Integer.MIN_VALUE;
		for(int i = 0; i < N; i++){
			int dis = a[i + 1] - a[i];
			max = Math.max(max, dis);
		}
		System.out.println(K - max);
		
	}
}
