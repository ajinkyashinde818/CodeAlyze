import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		String s = scanner.next();
		Set<Character>set=new HashSet<>();
		
		set.add(s.charAt(0));
		set.add(s.charAt(1));
		set.add(s.charAt(2));
		
		if(set.size()==3)System.out.println("Yes");
		else System.out.println("No");
	}
}
