import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Main {

	/* --------------------------------------------------------------------
	   main
	 * -------------------------------------------------------------------- */
	public static void main(String args[]) throws Exception {

		// ----- input -----
		Input input = new Input(System.in);
		final Data l = input.readLine();
		input.close();

		// ----- main -----
		int cnt = 0;
		for(int i = Math.min(l.col[0], l.col[1]); i > 0; i--) {
			if(l.col[0] % i == 0 && l.col[1] % i == 0) {
				if(++cnt == l.col[2]) {
					System.out.println(i);
					return;
				}
			}
		}
	}

	/* --------------------------------------------------------------------
	 * inupt class
	 * -------------------------------------------------------------------- */
	static class Input {

		public BufferedReader input;

		public Input(InputStream inStream) {
			input = new BufferedReader(new InputStreamReader(inStream));
		}

		public void close() throws Exception {
			input.close();
		}

		public Data readLine() throws Exception {
			return new Data(input.readLine().split(" "));
		}
	}
	/* --------------------------------------------------------------------
	 * data class
	 * -------------------------------------------------------------------- */
	static class Data{
		public int[] col;
		public Data(String[] values) {
			col = new int[values.length];
			for(int i=0; i < values.length; i++) {
				col[i] = Integer.parseInt(values[i]);
			}
		}
	}

}
