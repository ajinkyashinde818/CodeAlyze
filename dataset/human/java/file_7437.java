import java.util.ArrayDeque;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}

	String S;
	StringBuilder T = new StringBuilder();
	String P[] = {"dream", "dreamer", "erase", "eraser"};

	public void run() {
		Scanner sc = new Scanner(System.in);
		S = sc.next();

		ArrayDeque<Integer> stack = new ArrayDeque<Integer>();
		stack.push(0);
		boolean ans = false;
		while(!stack.isEmpty()) {
			int i = stack.pop();
			if(i == S.length()) {
				ans = true;
				break;
			}
			for(int j=0; j<4; j++) {
				if(i+P[j].length() <= S.length() && P[j].equals(S.substring(i, i+P[j].length()))) {
					stack.push(i+P[j].length());
				}
			}
		}

		if(ans) System.out.println("YES");
		else System.out.println("NO");

		sc.close();
	}
}
