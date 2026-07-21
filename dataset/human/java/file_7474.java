import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String S = sc.nextLine();
		
		int end = 0;
		String[] map = {"dream", "dreamer", "erase", "eraser"};
		while(end < S.length()) {
			boolean delete = false;
			for (String target: map) {
				if (S.length() - end - target.length() < 0) {
					continue;
				}
				
				if (S.substring(S.length() - end - target.length(), S.length() - end).equals(target)) {
					delete = true;
					end += target.length();
					break;
				}
			}
			
			if (!delete) {
				System.out.println("NO");
				return;
			}
		}
		
		System.out.println("YES");
	}
}
