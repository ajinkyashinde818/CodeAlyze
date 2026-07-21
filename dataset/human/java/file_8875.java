import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		new Main().solve(new Scanner(System.in));
	}

	public void solve(Scanner sc) {
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int k = Integer.parseInt(sc.next());
		
		List<Integer> results = new ArrayList<>();
		results.add(1);
		for(int i=2; i<=a && i<=b; i++) {
			if(a%i==0 && b%i==0){
				results.add(i);
			}
		}
		
		int index = results.size() - k;
		System.out.println(results.get(index));
	}
}
