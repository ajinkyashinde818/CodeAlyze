import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		sc.close();
		
		int ten = n/10;
		int one = n-ten*10;
		
		if(ten==9 || one==9) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}

	}

}
