import java.util.*;
public class Main{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		TreeSet<Integer> set = new TreeSet<Integer>();
		
		String s = sc.next(), t = sc.next();
		
		int arrs[] = new int[s.length()];
		int arrt[] = new int[t.length()];
		
		for(int i = 0; i<s.length(); i++) arrs[i] = (int)s.charAt(i);
		for(int i = 0; i<t.length(); i++) arrt[i] = (int)t.charAt(i);
		
		Arrays.sort(arrs); Arrays.sort(arrt);
		
		if(t.length() <= s.length()) {
			for(int i = 0; i<t.length(); i++) {
				if(arrs[i] > arrt[t.length()-i-1]) {
					System.out.println("No");
					System.exit(0);
				}
				else if(arrs[i] < arrt[t.length()-i-1]) {
					System.out.println("Yes");
					System.exit(0);
				}
			}
			System.out.println("No");
		}
		else {
			for(int i = 0; i<s.length(); i++) {
				if(arrs[i] > arrt[t.length()-i-1]) {
					System.out.println("No");
					System.exit(0);
				}
				else if(arrs[i] < arrt[t.length()-i-1]) {
					System.out.println("Yes");
					System.exit(0);
				}
			}
			
			System.out.println("Yes");
		}
		
		
		
		
	}

}
