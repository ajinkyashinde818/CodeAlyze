import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int k = sc.nextInt();
		int s = sc.nextInt();
		
		int[] nums = new int[k+1];
		
		for(int i=0; i<nums.length; i++) {
			nums[i] = i;
		}
		int count = 0;
		for(int i=0; i<nums.length; i++) {
			int x = nums[i];
			for(int j=0; j<nums.length; j++) {
				int y = nums[j];
				int z = s - x - y;
				if(z>=0 && z<=k) {
					count++;
				}
			}
		}
		System.out.println(count);
	}
}
