import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		String s = sc.nextLine();
		
		List<String> terms = Arrays.asList("eraser", "erase", "dreamer", "dream");
		
		
		
		for(String tar : terms) {
			s = s.replaceAll(tar, "");
		}
		
		if(s.equals("") || s.isEmpty()) {
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}
		
		
	}

}
