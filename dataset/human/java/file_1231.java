import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long[] sum = new long[n+1];
		for(int i=0;i<n;i++) {
			sum[i+1] = sum[i] + in.nextLong();
		}
		long min = Long.MAX_VALUE;
		for(int i=1;i<n;i++) {
			long num = abs(sum[i]*2-sum[n]);
			if(num<min) min = num;
		}
		System.out.println(min);
		in.close();

	}
	
	public static long abs(long a) {
		if(a<0) return -a;
		else return a;
	}

}
