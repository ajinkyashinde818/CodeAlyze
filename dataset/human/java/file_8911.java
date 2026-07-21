import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
 
public class Main {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
	
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		
		ArrayList<Integer> div = new ArrayList<>();
		
		int c = Math.min(a, b);
		for(int i = 1; i <= c; i++) {
			if((a % i == 0) && (b % i == 0)) div.add(i);
		}
		
		Collections.sort(div, Collections.reverseOrder());
		System.out.println(div.get(k-1));
		
		sc.close();
	}
 
}
