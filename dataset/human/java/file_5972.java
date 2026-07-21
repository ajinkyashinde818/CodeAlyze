import java.util.*;
class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		if (S.indexOf("a") != -1 && S.indexOf("b") != -1 && S.indexOf("c") != -1) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
