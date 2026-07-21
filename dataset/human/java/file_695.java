import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int joining = sc.nextInt();
		int displayRating = sc.nextInt();

		if(joining < 10 ){
			int result = 100*(10-joining);
			int results01 = displayRating + result;
			System.out.println(results01);
		}else{
			System.out.println(displayRating);
		}
		sc.close();
		}
  }
