import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		char[] s = sc.next().toCharArray();
		char[] t = sc.next().toCharArray();
		Arrays.sort(s);
		Arrays.sort(t);
		t = reverse(t);
		System.out.println(String.valueOf(s).compareTo(String.valueOf(t)) < 0 ? "Yes" : "No");
	}

	public static char[] reverse(char... c){
		char[] r = new char[c.length];
		for(int i = 0; i < c.length; i++){
			r[i] = c[c.length -1 -i];
		}
		return r;
	}
}
