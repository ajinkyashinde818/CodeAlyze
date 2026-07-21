import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next().replaceAll("eraser", "").replaceAll("erase", "").replaceAll("dreamer", "").replaceAll("dream", "");
		System.out.println((s.equals(""))? "YES" : "NO");
	}
}
