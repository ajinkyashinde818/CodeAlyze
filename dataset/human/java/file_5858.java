import java.util.Scanner;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.next();
		
		int counta = 0;
		int countb = 0;
		int countc = 0;

		for (int i = 0; i < 3; i++) {
			if(s.charAt(i) == 'a'){
				counta++;
			}
			
			if(s.charAt(i) == 'b'){
				countb++;
			}
			
			if(s.charAt(i) == 'c'){
				countc++;
			}		
		}
		
		if (counta == 1 && countb == 1 && countc == 1){
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
