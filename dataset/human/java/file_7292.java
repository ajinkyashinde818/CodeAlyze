import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		sc.close();

		String ans = "NO";
		if(s.matches("(dream|dreamer|erase|eraser)*")) ans = "YES";
		
		System.out.println(ans);
	}
}
