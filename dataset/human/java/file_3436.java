import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		// GET INPUT
		int N = sc.nextInt();
		
		
		// GET INPUT END
		
		sc.close();
		
		if(N % 10 == 9 || N >= 90) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}

	}

}
