import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long res = 0;
		long[] A = new long[N];
		int count = 0;
		A[0] = sc.nextLong();
      	if(A[0]<0)count++;
		long sum = Math.abs(A[0]);
		long min = Math.abs(A[0]);
		for(int i = 1;i<N;i++) {
			A[i] = sc.nextLong();
			sum += Math.abs(A[i]);
			if(Math.abs(A[i])<min) {
				min = Math.abs(A[i]);
			}
			if(A[i]<0)count++;
          //System.out.println(sum);
          //System.out.println(count);
		}
		if(count%2==1) {
			res = sum - 2*min;
		}else {
			res = sum;
		}


		System.out.println(res);


	}

}
