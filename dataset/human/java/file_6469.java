import java.util.Scanner;

public class Main {

	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		int k = scan.nextInt(), s = scan.nextInt();
		int result=0;
		for(int x=0; x<=k; x++) {
			for(int y=0; y<=k; y++) {
				int z = s-(x+y);
				if(z<=k && 0<=z)result++;
			}
		}
		System.out.println(result);
	}

}
