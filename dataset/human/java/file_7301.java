import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		new Main().solve(new Scanner(System.in));
	}
	
	public void solve(Scanner sc) {
		String s = sc.next();
		if(s.matches("^(dream|dreamer|erase|eraser)*$")){
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}
