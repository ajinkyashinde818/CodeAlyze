import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		sc.close();
		if(str.indexOf("a")!=-1 && str.indexOf("b")!=-1 && str.indexOf("c")!=-1) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
