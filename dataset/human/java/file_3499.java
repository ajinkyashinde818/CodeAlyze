import java.io.File;
import java.io.IOException;
import java.util.*;
 
public class Main {
 
	public static void main(String[] args) throws IOException {
		//File file = new File("input.txt");
		//Scanner sc = new Scanner(file);
		
		Scanner sc = new Scanner(System.in);
		
		String X = sc.next();
		String Y = sc.next();
		int ans = X.compareTo(Y);
		if(ans == 0) System.out.println("=");
		else System.out.println(ans < 0 ? "<" : ">");
	}
}
