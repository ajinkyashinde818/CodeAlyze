import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		
		s = s.replaceAll("eraser","");
		s = s.replaceAll("erase","");
		s = s.replaceAll("dreamer","");
		s = s.replaceAll("dream","");
		System.out.println(s.equals("")?"YES":"NO");
	}
}
