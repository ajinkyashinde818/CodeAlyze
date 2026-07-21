import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		s = s.replaceFirst("a","");
		s = s.replaceFirst("b","");
		s = s.replaceFirst("c","");
		System.out.println(s.equals("")? "Yes":"No");
	}
}
