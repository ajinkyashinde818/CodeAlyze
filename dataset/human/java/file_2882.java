import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[][] sheets = {
				{1,2,1,2,1,4,1,4}, 
                {1,2,1,4,1,4,1,2},
                {1,4,1,2,1,2,1,4},
                {1,4,1,4,1,2,1,2},
                {2,1,2,1,4,1,4,1},
                {2,1,4,1,4,1,2,1},
                {4,1,2,1,2,1,4,1},
                {4,1,4,1,2,1,2,1}};
		int[] wait = new int[8];
		StringBuilder sb = new StringBuilder();
		while (in.hasNext()) {
			String[] nums = in.nextLine().split("\\s");
			Arrays.fill(wait, 0);
			for (int i = 0; i < 8; i++) {
				wait[i] = Integer.parseInt(nums[i]);
			}
			int[] ans = null;
			int min = Integer.MAX_VALUE;
			for (int[] set : sheets) {
				int amari = 0;
				for (int i = 0; i < 8; i++) {
					amari += Math.max(0, wait[i] - set[i]);
				}
				if (min > amari) {
					ans = set;
					min = amari;
				}
			}
			sb.setLength(0);
			for (int i : ans) {
				sb.append(i);
				sb.append(" ");
			}
			sb.setLength(sb.length() - 1);
			System.out.println(sb.toString());
		}
		in.close();
	}

}
