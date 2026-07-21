import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		sc.close();
		
		char[] sElem = new char[s.length()];
		for(int i = 0;i < s.length();++i)
			sElem[i] = s.charAt(i);
		char[] tElem = new char[t.length()];
		for(int i = 0;i < t.length();++i)
			tElem[i] = t.charAt(i);
		Arrays.sort(sElem);
		Arrays.sort(tElem);
		
		boolean flag = true;
		for(int i = 0;i < s.length();++i) {
			if(sElem[i] < tElem[t.length()-1-i]) {
				flag = true;
				break;
			} else if(sElem[i] > tElem[t.length()-1-i]) {
				flag = false;
				break;
			} else if(i == t.length()-1) {
				flag = false;
				break;
			}
		}
		if(flag)
			System.out.println("Yes");
		else
			System.out.println("No");
	}
}
