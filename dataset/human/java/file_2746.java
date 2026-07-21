import java.util.Arrays;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String s1 = scan.next();
		String s2 = scan.next();

		char[] chars1 = s1.toCharArray();
		Arrays.sort(chars1);
		char[] chars2 = s2.toCharArray();
		Arrays.sort(chars2);

		String ns1 = new String(chars1);
		String ns2 = new String(chars2);
		StringBuilder sb = new StringBuilder(ns2);
		ns2 = sb.reverse().toString();

		if(ns1.compareTo(ns2) < 0){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}
		scan.close();
	}

}
