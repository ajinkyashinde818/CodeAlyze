import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int allMeters = sc.nextInt();
		int numberOfHouse = sc.nextInt();

		int[] housePlase = new int[numberOfHouse];
		List<Integer> moveMeters = new ArrayList<>();
		int allMoveMeters = 0;

		for(int i = 0; i < numberOfHouse; i++) {
			 housePlase[i] = sc.nextInt();
		}
		for(int i = numberOfHouse - 1; i > 0; i--) {
			moveMeters.add(housePlase[i] - housePlase[i - 1]);
		}
		moveMeters.add(allMeters - housePlase[numberOfHouse - 1] + housePlase[0]);
		Collections.sort(moveMeters, Collections.reverseOrder());
		int count = 0;
		for(int li : moveMeters) {
			count++;
			if(count != 1) allMoveMeters = allMoveMeters + li;
		}
		System.out.println(allMoveMeters);
	}
}
