import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int[] nums = new int[num];
		int minusNum = 0, zeroNum = 0, min = 1000000000;
		BigInteger ans = BigInteger.ZERO;
		for(int i = 0; i < num; i++) {
			nums[i] = sc.nextInt();
			if(nums[i] == 0) {
				zeroNum++;
			} else if(nums[i] < 0) {
				minusNum++;
				nums[i] = -nums[i];
			}
			min = min > nums[i] ? nums[i] : min;
			ans = ans.add(BigInteger.valueOf(nums[i]));
		}
		if(zeroNum == 0 && minusNum % 2 == 1) {
			ans = ans.subtract(BigInteger.valueOf(min*2));
		}
		System.out.println(ans);
	}
}
