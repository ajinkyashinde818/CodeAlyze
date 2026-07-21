import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		
		String dream = "dream";
		String dreamer = "dreamer";
		String erase = "erase";
		String eraser = "eraser";
		
		str = str.replaceAll(eraser, "");
		str = str.replaceAll(erase, "");
		str = str.replaceAll(dreamer, "");
		str = str.replaceAll(dream, "");
		
		if(str.length() == 0) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}
