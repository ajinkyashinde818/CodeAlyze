import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		long[] vals = new long[N];
		
		long sum = 0;
		int count = 0;
		long min = Long.MAX_VALUE;
		
		for(int i = 0; i < N; i++){
			vals[i] = sc.nextInt();
			if(vals[i] < 0) {
				count++;
				vals[i] = -vals[i];
			}
			if(vals[i] < min) min = vals[i];
			sum += vals[i];
		}
		
		System.out.println(count % 2 == 0? sum : sum - 2 * min);
	}
}
