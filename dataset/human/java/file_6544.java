import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		SumOfThreeIntegers solver = new SumOfThreeIntegers();
		solver.readInput();
		solver.solve();
		solver.writeOutput();
	}

	static class SumOfThreeIntegers {
		private int k;
		private int s;
		private Scanner scanner;
		private int output;

		public SumOfThreeIntegers() {
			scanner = new Scanner(System.in);
			output = 0;
		}

		public void readInput() {
			k = scanner.nextInt();
			s = scanner.nextInt();
		}

		public void solve() {
			for(int x=0; x<=k;x++) {
				for(int y=0; y<=k;y++) {
					if(s-x-y <= k && s-x-y>=0) {
						output++;
					}
				}
			}

		}

		public void writeOutput() {
			System.out.print(output);
		}

	}

}
