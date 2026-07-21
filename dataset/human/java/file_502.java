import java.util.Scanner;

public class Main {
	public static void main(String[] args ) {

		Scanner scanner = new Scanner(System.in);
		int numOfJoin = scanner.nextInt();
		int dispRating = scanner.nextInt();
		int internalRating;

		if(numOfJoin<10&&numOfJoin>0) {
			internalRating = dispRating + 100*(10-numOfJoin);
		}else {
			internalRating = dispRating ;
		}

		System.out.println(internalRating);

		scanner.close();
	}
}
