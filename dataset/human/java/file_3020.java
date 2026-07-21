import java.util.HashSet;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		HashSet<Integer>aset = new HashSet<Integer>();
		HashSet<Integer>bset = new HashSet<Integer>();
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		for(int i = 0; i< m ; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			if(a == 1) {
				bset.add(b);
				}
			if(b == n) {
				aset.add(a);
			}
		}
		sc.close();
		
		aset.retainAll(bset);
		
		if(!aset.isEmpty()) {
			System.out.println("POSSIBLE");
		}
		else {
			System.out.println("IMPOSSIBLE");
		}
	
	}
	

	
}
