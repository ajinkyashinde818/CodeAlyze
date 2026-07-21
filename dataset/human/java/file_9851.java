import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();

		int[] c = new int[n];
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) {
			c[i] = sc.nextInt();
			for (int j = 0; j < m; j++)
				a[i][j] = sc.nextInt();
		}

		int length = (int) Math.pow(2, n);
		int min = Arrays.stream(c).sum();
		boolean isAssigned = false;
		for (int i = 1; i < length; i++) {
			int costSum = 0;
			int[] valSum = new int[m];
			
			String cursor = Integer.toBinaryString(i);
			//System.out.print("cursor: " + cursor + " -> ");
			for (int j = cursor.length() - 1; j >= 0; j--) {
				if (cursor.charAt(j) == '1') {
					int index = cursor.length() - j - 1;
					//System.out.print(index);
					costSum += c[index];
					for(int k = 0; k < m; k++) {
						valSum[k] += a[index][k];
					}
				}
			}
			//System.out.println();
			
			boolean allOK = true;
			for(int j = 0; j < m; j++) {
				if(valSum[j] < x) {
					allOK = false;
					break;
				}
			}
			if(allOK && costSum <= min) {
				min = costSum;
				isAssigned = true;
			}
		}
		
		if(isAssigned)
			System.out.println(min);
		else
			System.out.println(-1);
	}
}
