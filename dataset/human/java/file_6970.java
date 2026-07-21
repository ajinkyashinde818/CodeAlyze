import java.util.Arrays;
import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		
		int K=sc.nextInt();
		int N=sc.nextInt();
		int[] A=new int[N];
		int[] B=new int[N];
		
		for(int i=0;i<N;i++) {
			A[i]=sc.nextInt();
		}
		
		B[0]=A[0]+(K-A[N-1]);
		
		for(int i=1;i<N;i++) {
			B[i]=A[i]-A[i-1];
		}
		
		int sum=0;
		
		Arrays.sort(B);
		
		for(int i=0;i<N-1;i++) {
			sum+=B[i];
		}
		
		System.out.print(sum);
		
		sc.close();
	}
}
