import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String n = scan.next();
		int[] x = new int[1000002];
		String[] sliced = n.split("");
		int digits = 0;
		for(int i = sliced.length - 1; i >= 0; i--) {
			x[digits++] = Integer.parseInt(sliced[i]);
		}
		x[digits] = 0;
		long output = 0;
		for(int i = 0; i < digits + 1; i++) {
			if(x[i] < 5) {
				output += x[i];
			} else if( x[i] == 5) {
				if(x[i+1] < 5) {
					output += x[i];
				} else {
					output += 10 - x[i];
					x[i+1]++;
				}
			} else {
				output += 10 - x[i];
				x[i+1]++;
			}
		}
		System.out.println(output);
		scan.close();
	}

}
