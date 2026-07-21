import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		sc.close();
		s = s.replaceAll("eraser", "-");
		s = s.replaceAll("erase", "-");
		s = s.replaceAll("dreamer", "-");
		s = s.replaceAll("dream", "-");
		s = s.replaceAll("-", "");
		if(s.length() == 0) {
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}
	}
}
