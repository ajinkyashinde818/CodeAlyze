import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int rate = scan.nextInt();
		if(rate < 1200){
			System.out.print("ABC");
		}
		else{
			System.out.print("ARC");
		}

	}

}
