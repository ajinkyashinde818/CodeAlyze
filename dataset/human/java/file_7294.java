import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	private static ArrayList<String>divide = new ArrayList<String>(){{
		add("dream");
		add("dreamer");
		add("erase");
		add("eraser");
	}};
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s = in.nextLine();
		String str = new StringBuilder(s).reverse().toString();
		divide = Main.divide.stream().map(e -> new StringBuilder(e).reverse().toString())
				.collect(ArrayList<String>::new, ArrayList<String>::add, ArrayList<String>::addAll);
		;

		boolean can = true;
		for (int i = 0; i < str.length();) {
			boolean can2 = false;
			for (int j = 0; j < 4; j++) {
				String d = divide.get(j);
				if ((d.length() - (str.length() - i) <= 0) 
						&& str.substring(i, i + d.length()).equals(d)) {
					can2 = true;
					i += d.length();
				}
			}
			if (!can2) {
				can = false;
				break;
			}
			
		}
		
		String answer = (can) ? "YES" : "NO";
		System.out.println(answer);
		

	}

}
