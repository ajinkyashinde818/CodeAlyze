import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		int K = stdIn.nextInt();
		int N = stdIn.nextInt();
		
		ArrayList<Integer> A = new ArrayList<Integer>();
		for(int i = 0; i < N; i ++) {
			A.add(stdIn.nextInt());
		}
		
		Collections.sort(A);
		int distance = 0;
		for(int i = 0; i < A.size(); i ++) {
			if(i == 0) {
				distance += A.get(i);
			}else {
				distance += A.get(i) - A.get(i - 1);
			}
			
			if(i == A.size() - 1) {
				distance += K - A.get(i);
			}
		}
		
		int longest = A.get(0) + K - A.get(A.size() - 1);
		
		for(int i = 1; i < A.size(); i ++) {
			longest = Math.max(longest, A.get(i) - A.get(i - 1));
		}
		
		System.out.println(distance - longest);
	}
}
