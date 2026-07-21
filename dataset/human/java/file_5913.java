import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		sc.close();
		
		Set<Character> set = new HashSet<>();
		for(int i = 0;i < S.length();++i)
			set.add(S.charAt(i));
		if(set.size() == 3)
			System.out.println("Yes");
		else
			System.out.println("No");
	}
}
