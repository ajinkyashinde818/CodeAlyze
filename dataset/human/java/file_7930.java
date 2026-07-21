import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int count = 0;
		for(int i = 0;i < 10;i++){
			int n = in.nextInt();
			count = count + n;
		}
		System.out.println(count);
	}
}
