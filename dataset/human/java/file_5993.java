import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		StringBuilder s = new StringBuilder();
		s.append(br.readLine());
		System.out.println(new Problem(s).solve());
		
		
		br.close();
	}
	
}
class Problem{
	StringBuilder s;
	
	public Problem(StringBuilder s) {
		this.s = s;
	}
	public String solve() {
		String result="No";
		
		if (s.toString().contains("a")
				&& s.toString().contains("b")
				&& s.toString().contains("c")) {
			result="Yes";
		}	
		return result;
	}
}
