import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int K = scanner.nextInt();
		int N = scanner.nextInt();
		List<Integer> A = new ArrayList<Integer>();
		for(int i =0; i<N; i++) {
			A.add(scanner.nextInt());
		}
		Collections.sort(A);
		List<Integer> B = new ArrayList<Integer>();
			for(int i=0; i<N;i++) {
				if(i+1 < N) {
					B.add(Math.abs(A.get(i)-A.get(i+1)));
				}else {
					B.add(K-Math.abs(A.get(i)-A.get(0)));
				}
			}
			int Max = B.get(0);
			for(int i = 1 ; i < B.size(); i++){
		        if(Max < B.get(i)){
		            Max = B.get(i);
		            }
		        }
		System.out.println(K-Max);
		
		
	}
}
