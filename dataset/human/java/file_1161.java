import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		long[] souwa=new long[N];
		long sum=0;

		int[] cd=new int[N];
		for(int i=0; i<N; i++) {
			cd[i]=sc.nextInt();
		}
		souwa[0]=cd[0];
		sum=cd[0];

		for(int i=1; i<N; i++) {
			souwa[i]=souwa[i-1]+cd[i];
			sum+=cd[i];
		}
		long min_diff=9223372036854775807L;

		for(int i=0; i<N-1; i++) {
			min_diff=Math.min(Math.abs(2*souwa[i]-sum),min_diff);
		}
		System.out.println(min_diff);
	}
}
