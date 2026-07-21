import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		long[] A=new long[N];
		long min=100000000;
		int mincount=0;
		for(int i=0;i<N;i++) {
			A[i]=sc.nextLong();
			if(A[i]<0) {
				mincount++;
			}
			if(Math.abs(A[i])<min) {
				min=Math.abs(A[i]);
			}
		}
		
		long sum=0;
		for(int i=0;i<N;i++) {
				sum+=Math.abs(A[i]);
		}
		if(mincount%2!=0) {
			sum-=2*min;
		}
		
		System.out.println(sum);
	}

}
