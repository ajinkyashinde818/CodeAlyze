import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		int rolls = sc.nextInt();
		
		String output = "No";
		int doubleRollCount = 0;
		
		for(int i = 0; i < rolls; i++) {
			int rollOne = sc.nextInt();
			int rollTwo = sc.nextInt();
			
			if(rollOne == rollTwo) {
				doubleRollCount++;
			}
			else {
				doubleRollCount = 0;
			}
			
			if(doubleRollCount == 3) {
				output = "Yes";
			}
		}
		
		System.out.println(output);
		
	}
}
