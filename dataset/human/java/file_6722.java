import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] l1 = br.readLine().split(" ");
		String[] l2 = br.readLine().split(" ");
		
		int k = Integer.parseInt(l1[0]);
		int n = Integer.parseInt(l1[1]);
		int[] a = Arrays.stream(l2).mapToInt(s -> Integer.parseInt(s)).toArray();
		
		int max = Integer.MIN_VALUE;
		for(int i = 1; i<n; ++i) {
			int dis = a[i] - a[i-1];
			if(max < dis) {
				max = dis;
			}
		}
		int dis = k - a[n -1] + a[0];
		if(max < dis) {
			max = dis;
		}
		
		System.out.println(String.format("%d", k - max));
		
	}

}
