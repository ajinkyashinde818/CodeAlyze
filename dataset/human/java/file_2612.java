import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		List<Character> array1 = new ArrayList<Character>();
		List<Character> array2 = new ArrayList<Character>();

		for(int i=0;i<s.length();i++){
		array1.add(s.charAt(i));
		}
		
		for(int i=0;i<t.length();i++){
		array2.add(t.charAt(i));
		}
		Collections.sort(array1);
		Collections.sort(array2);
		Collections.reverse(array2);
		for(int i=0;i<Math.min(s.length(), t.length());i++){
			if(array1.get(i)<array2.get(i)){
				System.out.println("Yes");
				System.exit(0);
			}else if(array1.get(i) == array2.get(i)){
				continue;
			}else{
				System.out.println("No");
				System.exit(0);
			}
		}
		if(s.length() >= t.length()){
			System.out.println("No");
		}else{
			System.out.println("Yes");
		}
		
	}
}
