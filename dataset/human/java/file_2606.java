import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		String t = sc.next();
		
		char[] sd = s.toCharArray();
		char[] items = t.toCharArray();

		Character[] td = new Character[items.length];
		
		for(int i=0, len=items.length; i<len; i++) {
			td[i] = Character.valueOf(items[i]);
		}
		
		Arrays.sort(sd);
		Arrays.sort(td, Collections.reverseOrder());
		
		s = String.valueOf(sd);
		
		for(int i=0, len=items.length; i<len; i++) {
			items[i] = td[i].charValue();
		}
		
		t = String.valueOf(items);
		
		
		if(s.compareTo(t) <= -1) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
		
		sc.close();
	}
}
