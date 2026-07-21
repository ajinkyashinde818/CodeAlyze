import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Main {

	public static void main(String[] args) throws IOException {
		Main main = new Main();
		main.run();
	}

	private void run() throws IOException {
		PrintWriter out = new PrintWriter(System.out);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] values = br.readLine().split(" ");
		int K = Integer.parseInt(values[0]);
		int N = Integer.parseInt(values[1]);
		values = br.readLine().split(" ");
		int max = 0;
		for(int i = 0; i < N-1; i++) {
			int dif = Integer.parseInt(values[i+1]) - Integer.parseInt(values[i]);
			if(dif > max) {
				max = dif;
			}
		}
		int dif = K+Integer.parseInt(values[0]) - Integer.parseInt(values[N-1]);
		if(dif > max) {
			max = dif;
		}
		int result = K - max;
		out.println(result);
		out.flush();
		br.close();
	}
}
