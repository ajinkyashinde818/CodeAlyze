import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		int K = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		
		int[] nums = new int[2*N];
		
		st = new StringTokenizer(in.readLine());
		for(int i = 0; i < N; i++) {
			nums[i] = Integer.parseInt(st.nextToken());
			nums[i+N] = nums[i] + K;
		}
		
		int min = Integer.MAX_VALUE;
		for(int i = 0; i + N-1 < 2*N; i++) {
			min = Math.min(min, nums[i+N-1] - nums[i]);
		}
		
		System.out.println(min);
	}
}
