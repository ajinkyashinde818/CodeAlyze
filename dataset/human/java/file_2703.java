import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner =new Scanner(System.in);
		String oBefore = scanner.nextLine();
		String oBehind = scanner.nextLine();

		
		char[] before = oBefore.toCharArray();
		char[] behind = oBehind.toCharArray();
		
		Arrays.sort(before);
		Arrays.sort(behind);
		
		char[] reverse = new char[behind.length];
		for (int i = 0; i < reverse.length; i++) {
			reverse[reverse.length-i-1] = behind[i];			
		}
		
		String ans = "Yes";
		if (String.valueOf(before).compareToIgnoreCase(String.valueOf(reverse))>=0 ) {
			ans="No";
		}
		
		System.out.println(ans);
		scanner.close();
	}

}
