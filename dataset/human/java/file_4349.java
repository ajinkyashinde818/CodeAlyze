import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int dishNum = sc.nextInt();
		
		ArrayList<Integer> eatOrder = new ArrayList<>();
		for(int i = 0; i < dishNum; i++) {
			eatOrder.add(sc.nextInt());
		}
		
		ArrayList<Integer> firstSatisfaction = new ArrayList<>();
		for(int i = 0; i < dishNum; i++) {
			firstSatisfaction.add(sc.nextInt());
		}
		
		ArrayList<Integer> secondSatisfaction = new ArrayList<>();
		for(int i = 0; i < dishNum-1; i++) {
			secondSatisfaction.add(sc.nextInt());
		}

		int result = 0;
		for(int i = 0; i < dishNum; i++) {
			int eatNum = eatOrder.get(i);
			result += firstSatisfaction.get(eatNum-1);
			
			if(i != dishNum-1) {
				int eatNumNext = eatOrder.get(i+1);
				if(eatNum+1 == eatNumNext) {
					result += secondSatisfaction.get(eatNum-1);
				}	
			}
		}
		
		System.out.println(result);
		sc.close();
	}
}
