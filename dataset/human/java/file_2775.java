import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] s=sc.next().toCharArray(),t=sc.next().toCharArray();
		Arrays.sort(s);
		Arrays.sort(t);
		String sd = new String(s);
		String td = new String(t);
		td = new StringBuilder(td).reverse().toString();
		System.out.println(sd.compareTo(td)<0?"Yes":"No");
	}
}
