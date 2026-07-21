import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int cnta = 0;
		int cntb = 0;
		int cntc = 0;
		for(int i = 0 ; i < 3 ; i++) {
			if(s.charAt(i) == 'a') cnta++;
			if(s.charAt(i) == 'b') cntb++;
			if(s.charAt(i) == 'c') cntc++;
		}
		if(cnta == 1 && cntb == 1 && cntc == 1) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
