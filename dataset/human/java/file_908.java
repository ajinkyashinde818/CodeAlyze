import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int now = scanner.nextInt();
		if(n<10) {
			System.out.println(now+100*(10-n));
		}else {
			System.out.println(now);
		}
	}	
	
}
