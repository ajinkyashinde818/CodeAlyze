import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		int n = kb.nextInt();
		int r = kb.nextInt();
		if(n >= 10) {
			System.out.println(r);
			return;
		} 
		int ans = r + 100*(10-n);
		System.out.println(ans);
	}
}
