import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) throws Exception {
		String str=sc.nextLine();
		System.out.println(str.substring(0,str.length()-8));
	}
}
