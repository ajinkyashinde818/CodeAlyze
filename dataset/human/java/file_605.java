import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

	Scanner sca = new Scanner(System.in);
	int n = sca.nextInt();
	int r = sca.nextInt();
	int ans = 0;
	if(n >= 10) {
		ans = r;
	}
	else {
		ans = r + 100*(10 - n);
	}
	System.out.println(ans);

	// 後始末
	sca.close();
	}
}
