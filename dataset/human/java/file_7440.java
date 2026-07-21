import java.util.Scanner;
import java.util.regex.Pattern;

public class Main {
	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		String s=scanner.next();
		Pattern p=Pattern.compile("^(dream|dreamer|erase|eraser)+$");
		if(p.matcher(s).find()) {
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}
	}
}
