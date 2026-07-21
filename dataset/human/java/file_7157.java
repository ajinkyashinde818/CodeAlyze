import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		try(Scanner sc = new Scanner(System.in)) {
			
			int k = sc.nextInt();			
			int n = sc.nextInt();
			int[] aArray = new int[n];
			
			for(int i = 0 ; i < n ; i++ ) {
				aArray[i] = sc.nextInt();
			}
			
			PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
			
			for(int i = 0 ; i < n ; i++ ) {
				if ( i == 0 ) {
					int dist = k - aArray[n-1] + aArray[0];
					pq.add(dist);
				}
				else {
					pq.add(aArray[i] - aArray[i-1]);
				}
			}
			
			int max = pq.poll();
			
			System.out.println(k - max);
			
		}
	}

}
