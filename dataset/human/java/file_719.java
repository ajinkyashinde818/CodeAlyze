import java.util.*;
public class Main {

	public static void main(String[] args) {
		//  input
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		int r = Integer.parseInt(sc.next());
		
		// output & judge
		if(n >= 10) {
			System.out.println(r);
		}else {
			System.out.println(100 * (10 - n) + r);
		}
	}
}
