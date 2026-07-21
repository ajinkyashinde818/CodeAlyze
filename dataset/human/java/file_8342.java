import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

	Scanner sca = new Scanner(System.in);
	int a = sca.nextInt();
	int b = sca.nextInt();
	long c = (long)a*(long)b;
	int index;
	if(a > b) {
		index = b;
	}
	else {
		index = a;
	}
	for(int i = index; i >= 1; i--) {
		if(a % i == 0 && b % i == 0) {
			System.out.println(c/i);
			break;
		}
	}

	sca.close();
	}
}
