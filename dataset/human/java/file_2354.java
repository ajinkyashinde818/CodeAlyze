import java.util.*;
class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		char[] charArray = S.toCharArray();
		for (int i = 0; i < S.length() - 8; i++) {
			System.out.print(charArray[i]);
		}
	}
}
