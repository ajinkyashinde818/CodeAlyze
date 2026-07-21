import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (true) {
			int n = in.nextInt();
			if(n==0) break;
			ArrayList<ArrayList<Character>> head = new ArrayList<>();
			String[] body = new String[n];
			for (int i = 0; i < n; i++) {
				head.add(new ArrayList<Character>());
				String txt = in.next();
				int j = 0;
				while (txt.charAt(j) == '.') {
					head.get(i).add(' ');
					j++;
				}
				body[i] = txt.substring(j);
			}

			for (int i = 0; i < n; i++) {
				ArrayList<Character> line = head.get(i);
				int col = line.size() - 1;
				if (line.size() == 0)
					continue;
				line.set(col, '+');
				int j = i - 1;
				while (head.get(j).size() - 1 > col) {
					head.get(j).set(col, '|');
					j--;
				}
			}

			for (int i = 0; i < n; i++) {
				ArrayList<Character> line = head.get(i);
				for (int j = 0; j < line.size(); j++) {
					System.out.print(line.get(j));
				}
				System.out.println(body[i]);
			}
			System.gc();
		}
	}
}
