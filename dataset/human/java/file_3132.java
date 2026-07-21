import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String N = scan.next();
		char [] date = N.toCharArray();

		if(date[0]=='9'|| date[1]=='9' ){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}

}
}
