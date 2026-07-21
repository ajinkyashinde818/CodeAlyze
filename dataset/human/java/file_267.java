import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long[] a = new long[n];
		long[] abs = new long[n];
		long absmin = Long.MAX_VALUE;
		long sum = 0;
		int count = 0;
		for(int i=0;i<n;i++) {
			a[i] = in.nextInt();
			if(a[i]<0) count++;
			abs[i] = Math.abs(a[i]);
			if(abs[i]<absmin) absmin = abs[i];
			sum += abs[i];
		}
		System.out.println(count%2==0?sum:sum - absmin*2);
		in.close();
	}

}
