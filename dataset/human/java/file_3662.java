import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Exception {
		new Main().run();
	}
	
	void run() {
		Scanner sc=new Scanner(System.in);
		char x=sc.next().charAt(0);
		char y=sc.next().charAt(0);
		int compare=Integer.compare((int)x, (int)y);
		System.out.println(compare==1?">":compare==-1?"<":"=");
	}
	
	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
	
}
