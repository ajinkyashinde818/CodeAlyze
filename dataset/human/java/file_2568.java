import java.util.*;

public class Main {

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner stdin = new Scanner(System.in);

		char[] inS = stdin.next().toCharArray();
		Arrays.sort(inS);
		char[] inT = stdin.next().toCharArray();
		Arrays.sort(inT);

		String result = "No";
		for (int indexS = 0, indexT = (inT.length - 1); (indexS < inS.length) || (indexT >= 0); indexS++, indexT--) {
			if (indexS >= inS.length) {
				result = "Yes";
				break;
			}
			else if (indexT < 0) {
				result = "No";
				break;
			}

			if (inS[indexS] < inT[indexT]) {
				result = "Yes";
				break;
			}
			else if (inS[indexS] > inT[indexT]) {
				result = "No";
				break;
			}
		}

		System.out.println(result);
	}

}
