import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
	public static void main(String[] args) throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		char[] s = in.readLine().toCharArray();
		char[] t = in.readLine().toCharArray();
		Queue<Character> queS = new PriorityQueue<>(new Comparator<Character>() {
			@Override
			public int compare(Character o1, Character o2) {
				return Character.compare(o1, o2);
			}
		});
		Queue<Character> queT = new PriorityQueue<>(new Comparator<Character>() {
			@Override
			public int compare(Character o1, Character o2) {
				return -1 * Character.compare(o1, o2);
			}
		});
		for (int i = 0; i < s.length; ++i) {
			queS.add(s[i]);
		}
		for (int i = 0; i < t.length; ++i) {
			queT.add(t[i]);
		}

		boolean enable = false;
		boolean disable = false;
		Character charS, charT;
		while (!queS.isEmpty() && !queT.isEmpty()) {
			charS = queS.poll();
			charT = queT.poll();
			if (charS < charT) {
				// あきらかにOK
				enable = true;
				break;
			}
			if (charS > charT) {
				// どう頑張っても無理
				enable = false;
				disable = true;
				break;
			}
		}
		if (!enable && !disable) {
			if (queS.isEmpty() && !queT.isEmpty()) {
				enable = true;
			}
		}
		String result = enable ? "Yes" : "No";
		System.out.println(result);

	}
}
