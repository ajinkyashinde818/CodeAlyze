import java.util.Scanner;

class Main {
	public static void main(String args[]) {
	
		Scanner scan = new Scanner(System.in);
		
		String s = scan.next();
		String[] str = s.split("");
		
			if (str[0].equals(str[1]) || str[0].equals(str[2]) || str[1].equals(str[2])) {
			System.out.println("No");
			return;
			}
		
		System.out.println("Yes");
		
	}	
}
