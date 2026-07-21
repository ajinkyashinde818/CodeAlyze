import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str =sc.next();
		Set<String> set = new HashSet<>();

		for(int i=0;i<3;i++) {
			set.add(str.substring(i,i+1));
		}
		System.out.println(set.size()==3?"Yes":"No");

	}
}
