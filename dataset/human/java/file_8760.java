import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {

	/**
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int A = scan.nextInt();
		int B = scan.nextInt();
		int K = scan.nextInt();



		scan.close();

		List<Integer> l = new ArrayList<>();

		for(int i=1; i<=100; i++) {
			if(A%i==0 && B%i==0) {
				l.add(i);
			}
		}
		
		l.sort(Comparator.reverseOrder());
		
		
		System.out.println(l.get(K-1));
		
	}

}
