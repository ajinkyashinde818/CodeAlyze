import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int R = sc.nextInt();
		
		System.out.println(N>=10 ? R : R + (100*(10-N)));
		
		sc.close();
	}
}
