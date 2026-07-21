import java.util.Scanner;
import java.util.Arrays;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		char[] c = new char[3];
		for(int i=0; i<3; i++){
			c[i] = s.charAt(i);
		}
		Arrays.sort(c);
		System.out.println((c[0] == 'a' && c[1] == 'b' && c[2] == 'c') ? "Yes" : "No");
	}
}
