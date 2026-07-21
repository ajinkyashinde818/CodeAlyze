import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int n=sc.nextInt();
		long min=1145141919;
		long sum=0;
		int count=0;
		for(int i=0;i<n;i++) {
			long A=sc.nextLong();
			min =Math.min(min,Math.abs(A));
			sum+=Math.abs(A);
			if(A<0)count++;
		}
		System.out.println(count%2==0?sum:sum-2*min);
	}
}
