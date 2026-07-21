import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = 0;
		N = sc.nextInt();
		
		int[] nums = new int[N];
		
		int minus = 0;
		int min = 1000000000;
		int abs = 0;
		long sum = 0;
		
		for(int i=0; i < N; i++){
			nums[i] = sc.nextInt();
			abs = Math.abs(nums[i]);
			sum += abs;
			if(abs < min) {
				min = abs;
			}
			if(nums[i] < 0) {
				minus++;
			}
		}
		
		sc.close();
		
		if(minus % 2 == 0) {
			System.out.println(sum);
		}else {
			System.out.println(sum - 2 * min);
		}

	}

}
