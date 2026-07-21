import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	private char max(char[] a) {
		char result = a[0];
		for(int i=1;i<a.length;i++) {
			result = result < a[i] ? a[i] : result;
		}
		return result;
	}
	private char min(char[] a) {
		char result = a[0];
		for(int i=1;i<a.length;i++) {
			result = result > a[i] ? a[i] : result;
		}
		return result;
	}
	
	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		String s = sc.next();
		String t = sc.next();
		sc.close();

		List<Character> cs = new ArrayList<>();
		List<Character> ct = new ArrayList<>();
		
		for(int i=0;i<s.length();i++) {
			cs.add(s.charAt(i));
		}
		for(int i=0;i<t.length();i++) {
			ct.add(t.charAt(i));
		}
		
		cs.sort(Comparator.naturalOrder());
		ct.sort(Comparator.reverseOrder());
		
		if(cs.size() >= ct.size()) {
			for(int i=0;i<ct.size();i++) {
				if(cs.get(i) == ct.get(i)) {
					continue;
				}
				if(cs.get(i) < ct.get(i)) {
					out.println("Yes");
					return;
				}else {
					out.println("No");
					return;
				}
			}
			out.println("No");
		}else if(cs.size() < ct.size()) {
			for(int i=0;i<cs.size();i++) {
				if(cs.get(i) == ct.get(i)) {
					continue;
				}
				if(cs.get(i) < ct.get(i)) {
					out.println("Yes");
					return;
				}else {
					out.println("No");
					return;
				}
			}
			out.println("Yes");
		}
		
	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}
