import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Exception {
		new Main().run();
	}
	
	void run() {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int R=sc.nextInt();
		if(N>=10) {
			System.out.println(R);
		}else {
			System.out.println(R+100*(10-N));
		}
	}
	
	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
	
}
