import java.io.IOException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException{
		Daydream solver = new Daydream();
		solver.readInput();
		solver.solve();
		solver.writeOutput();
	}

	static class Daydream {
		private String s;

		private Scanner scanner;
		private String output;

		public Daydream() {
			scanner = new Scanner(System.in);
		}

		public void readInput() {
			s = scanner.next();
		}

		public void solve() {
			String regex = "(dream(er)?|eraser?)+";
			output = s.matches(regex) ?"YES":"NO";

		}

		public void writeOutput() {
			System.out.println(output);
		}
	}


}
