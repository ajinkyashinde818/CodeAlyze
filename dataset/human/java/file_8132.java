import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Long A = sc.nextLong();
		Long B = sc.nextLong();
		int i = 1;
		Long Ai;
		while(true) {
			Ai = (long) (A * i);
			if(Ai % B == 0) {
				break;
			}
			i++;
		}
		System.out.println(Ai);
	}
}
