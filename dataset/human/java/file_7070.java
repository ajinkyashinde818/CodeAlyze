import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int K = scan.nextInt();
		int N = scan.nextInt();
		int[] A = new int[N];
		for(int i =0;i<N;i++) {
			A[i]=scan.nextInt();
		}

		int[] L = new int[N];

		for(int i =0;i<N-1;i++) {
			L[i]=A[i+1]-A[i];
//			System.out.println("i:"+i);
//			System.out.println("A[i+1]:"+A[i+1]);
//			System.out.println("A[i]:"+A[i]);
		}
		L[N-1]=K-A[N-1]+A[0];

//		for(int i =0;i<N;i++) {
//			System.out.println(L[i]);
//		}

		Arrays.sort(L);

		int sum = 0;

		for(int i =0;i<N-1;i++) {
			sum += L[i];
		}

		System.out.println(sum);
	}
}
