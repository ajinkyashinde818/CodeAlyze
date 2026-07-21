import java.util.Arrays;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	static Map<Integer, Integer> map = new LinkedHashMap<>();

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		String s = scanner.next();
		String t = scanner.next();
		char s1[]=new char[s.length()];
		char t1[]=new char[t.length()];
		
		for(int i=0;i<s.length();i++) {
			s1[i]=s.charAt(i);
		}
		Arrays.sort(s1);
		
		for(int i=0;i<t.length();i++) {
			t1[i]=t.charAt(i);
		}
		Arrays.sort(t1);
		
		
		int cnt=0;
		for(int i=0;i<Math.min(s.length(), t.length());i++) {
			if(s1[i]<t1[t.length()-1-i]) {
				System.out.println("Yes");
				return;
			}else if(s1[i]==t1[t.length()-1-i]) {
				cnt++;
			}else {
				System.out.println("No");
				return;
			}
		}
		if(cnt==Math.min(s.length(), t.length())&&s.length()<t.length()) {
			System.out.println("Yes");
			return;
		}
		if(cnt==Math.min(s.length(), t.length())&&s.length()>=t.length()) {
			System.out.println("No");
			return;
		}
		
		System.out.println("Yes");

	}

}
