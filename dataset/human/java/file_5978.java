import java.io.*;
import java.math.*;
import java.util.*;
public class Main { 
 
	public static void main(String[] args) { 
		Scanner input = new Scanner(System.in);
		String S = input.next();
		String ans = "No";
		if (S.charAt(0)!=S.charAt(1)&&S.charAt(1)!=S.charAt(2)&&S.charAt(0)!=S.charAt(2)) {
			ans="Yes";
		}
		System.out.println(ans);
	}	
}
