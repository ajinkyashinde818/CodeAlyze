import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		
		List <Integer> Adivisor = new ArrayList<Integer>();
		List <Integer> Bdivisor = new ArrayList<Integer>();
		List <Integer> ABdivisor = new ArrayList<Integer>();
		
		for(int i=1; i<=A; i++) {
			if(A%i==0) {
				Adivisor.add(A/i);
			}
		}
		
		for(int i=1; i<=B; i++) {
			if(B%i==0) {
				Bdivisor.add(B/i);
			}
		}
		
		for(int i=0; i<Adivisor.size(); i++) {
			for(int j=0; j<Bdivisor.size(); j++) {
				if(Adivisor.get(i)==Bdivisor.get(j)) {
					ABdivisor.add(Adivisor.get(i));
				}
			}
		}
		
		System.out.print(ABdivisor.get(K-1));
	}
}
