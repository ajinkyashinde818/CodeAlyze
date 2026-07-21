import java.util.*;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int r = sc.nextInt();

		if (n<10) {
			int sum = 100*(10-n);
			System.out.println(r+sum);
		}else{
			System.out.println(r);
		}



	}
}
