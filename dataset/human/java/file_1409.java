import java.io.*;
import java.math.*;
import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		int M = input.nextInt();
		String[] big = new String[N];
		String[] small = new String[M];
		boolean YES=false;
		for (int i = 0; i < N; i++) {
			big[i] = input.next();
		}
		for (int i = 0; i < M; i++) {
			small[i] = input.next();
		}
		for (int level = 0; level <= N-M; level++) { //Vertical shift
			for (int index = 0; index <= N-M; index++) { //Horizontal shift
				boolean bad = false;
				for (int r = level; r < level+M; r++) { //Checking subcomponent
					for (int c = index; c < index+M; c++) {
						char BigMatrix = big[r].charAt(c);
						char SmallMatrix = small[r-level].charAt(c-index);
						if (BigMatrix!=SmallMatrix) {
							bad=true;
							break;
						}
					}
					if (bad) break;
				}
				if (!bad) {
					YES=true;
					break;
				}
			}
			if (YES) break;
		}
		System.out.println(YES?"Yes":"No");
	}
}
