import java.util.*;
// warm-up
// Will this ordering work? 
public class Main {

	static void solve() {
		Scanner sc = new Scanner(System.in);
		StringBuilder s = new StringBuilder(sc.next().replaceAll("eraser","")
			.replaceAll("erase","").replaceAll("dreamer","").replaceAll("dream",""));
		System.out.println(s.length()==0 ? "YES" : "NO");
		sc.close();			
	}

	public static void main(String args[]) {
		solve();
	}

}
