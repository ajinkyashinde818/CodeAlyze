import java.util.*;
public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		long K = sc.nextLong();
		int N = sc.nextInt();
		long max = 0;
		long buf;
		int i;
		long[] A = new long[N];
		for(i = 0;i < N;i++){
			A[i] = sc.nextLong();
		}
		for(i = 0;i < N;i++){
			if(i == N-1){
				buf = (K + A[0]) - A[i];
			}else{
				buf = A[i+1] - A[i];
			}
			if(buf > max){
				max = buf;
			}
		}
		System.out.println(K - max);
	}	
}
