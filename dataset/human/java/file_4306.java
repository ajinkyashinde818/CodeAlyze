import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		int[] order = new int[n];
		int[] satisfied = new int[n];
		int[] additinalSatisfied = new int[n];
		

		for(int i = 0 ; i < n ; i++ ) {
			order[i] = sc.nextInt();
		}
		
		for(int i = 0 ; i < n ; i++ ) {
			satisfied[i] = sc.nextInt();
		}
		
		for(int i = 0 ; i < n-1 ; i++ ) {
			additinalSatisfied[i+1] = sc.nextInt();
		}
		
		int previousOrder = Integer.MAX_VALUE;
		
		for(int i = 0 ; i < n ; i++ ) {
			if ( previousOrder != order[i] - 1) {
				additinalSatisfied[order[i]-1] = 0;
			}
			previousOrder = order[i];
		}
		
		int sum = 0;
		sum += Arrays.stream(satisfied).sum();
		sum += Arrays.stream(additinalSatisfied).sum();
		
		System.out.println(sum);
		
	}
}
