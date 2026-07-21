import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(new InputStreamReader(System.in));
		int a = sc.nextInt();

		if(a<1200){
			System.out.println("ABC");
		}else {
			System.out.println("ARC");
		}

	}
}
