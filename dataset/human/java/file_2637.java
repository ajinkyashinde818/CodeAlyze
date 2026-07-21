import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		TwoAnagrams solver = new TwoAnagrams();
		solver.readInput();
		solver.solve();
		solver.writeOutput();
	}

	static class TwoAnagrams {

		private String sInput;
		private String tInput;
		private String answer;
		private Scanner scanner;

		public TwoAnagrams() {
			scanner = new Scanner(System.in);
		}

		public void readInput() {
			sInput = scanner.nextLine();
			tInput = scanner.nextLine();
		}

		public void solve() {

			String[] sArray = sInput.split("");
			String[] tArray = tInput.split("");

			Arrays.sort(sArray);
			Arrays.sort(tArray,Collections.reverseOrder());

			String s = String.join("", sArray);
			String t = String.join("",tArray);
			if(0 < t.compareTo(s)) {
				answer = "Yes";
			} else {
				answer = "No";
			}
		}

		public void writeOutput() {
			System.out.println(answer);
		}
	}

}
