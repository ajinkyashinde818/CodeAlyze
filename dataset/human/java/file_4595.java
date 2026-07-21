import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int answer = 0;
		if(a + b >= c - 1) answer = b + c;
		else answer = a + b*2 + 1;
		System.out.println(answer);
	}

}
