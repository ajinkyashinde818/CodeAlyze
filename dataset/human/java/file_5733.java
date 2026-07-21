import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int[] checkAry = { 0, 0, 0 }; // a,b,c
		Scanner sc = new Scanner(System.in);
		String abc = sc.next();
		for (int i = 0; i < abc.length(); i++) {
			char c = abc.charAt(i);
			switch (c) {
			case 'a':
				checkAry[0] += 1;
				break;
			case 'b':
				checkAry[1] += 1;
				break;
			case 'c':
				checkAry[2] += 1;
				break;
			}
		}
		int tmp = 0;
		for (int i = 0; i < abc.length(); i++) {
			if(checkAry[i]==0) {
				break;
			}
			tmp++;
		}
		String answer = tmp == 3 ? "Yes" : "No";
		System.out.print(answer);
	}
}
