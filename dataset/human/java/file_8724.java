import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int A = in.nextInt();
		int B = in.nextInt();
		int K = in.nextInt();
		in.close();

		List<Integer> nums = new ArrayList<>();
		for (int i = Math.min(A, B); i >= 1; --i) {
			if (A % i == 0 && B % i == 0) {
				nums.add(i);
			}
		}
		System.out.println(nums.get(K - 1));
	}

}
