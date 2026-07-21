import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		String s = sc.next();
		String t = sc.next();

		char[] s_chars = s.toCharArray();
		Arrays.sort(s_chars);
		s = String.valueOf(s_chars);

		char[] t_chars = t.toCharArray();
		Arrays.sort(t_chars);
		t = String.valueOf(t_chars);


		String t_desc = new StringBuilder(t).reverse().toString();

		if(s.compareTo(t_desc) < 0){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}

	}
}
