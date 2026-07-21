import java.util.*;

class Main {
	Scanner sc;
	int N, R;
	
	private void calc() {
		sc = new Scanner(System.in);
		N = sc.nextInt();
		R = sc.nextInt();
		
		int K = (N>9)?R:R+100*(10-N);
		System.out.println(K);
	}

	public static void main(String[] args) {
		new Main().calc();
	}
}
