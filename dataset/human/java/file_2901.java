import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
	private	static	BufferedReader	br = null;

	static {
		br = new BufferedReader(new InputStreamReader(System.in));
	}
 
    /**
     * @param args
     */
	public static void main(String[] args) {
	// TODO Auto-generated method stub
		int[]	caps  = { 4, 1, 4, 1, 2, 1, 2, 1 };
		int[][]	waits = null;

		while ((waits = parseWaits()) != null) {
			int[]	tmp = null;
			int[]	min = { Integer.MAX_VALUE, Integer.MAX_VALUE };
			int		pos = 0;

			for (int i = 0; i < 8; i++) {
				tmp = new int[3];

				for (int j = 0; j < 8; j++) {
					tmp[2]  = (waits[(i + j) % 8][1] - caps[j] >= 0) ? waits[(i + j) % 8][1] - caps[j] : 0;
					tmp[0] += tmp[2];
					tmp[1] *= 10;
					tmp[1] += caps[(8 - i + j) % 8];
				}

				if (min[0] > tmp[0] || (min[0] == tmp[0] && min[1] > tmp[1])) {
					min[0] = tmp[0];
					min[1] = tmp[1];
					pos    = 8 - i;
				}
			}

			
			System.out.printf("%d %d %d %d %d %d %d %d\n",
					caps[(pos + 0) % 8],
					caps[(pos + 1) % 8],
					caps[(pos + 2) % 8],
					caps[(pos + 3) % 8],
					caps[(pos + 4) % 8],
					caps[(pos + 5) % 8],
					caps[(pos + 6) % 8],
					caps[(pos + 7) % 8]);
		}
	}

	private static  int[][] parseWaits() {
		int[][]		waits = null;
		String[]	split = null;
		String		strIn = null;
 
		if ((strIn = parseStdin()) != null) {
			split = strIn.split(" ");
			waits = new int[8][2];
			for (int n = 0; n < split.length; n++) {
				waits[n][0] = n;
				waits[n][1] = Integer.parseInt(split[n]);
			}
		}
		 
		return waits;
	}
 
	private static String parseStdin() {
		String	strNum = null;
 
		try {
			String line = br.readLine();
			if (line != null) {
				if (!line.isEmpty()) {
					strNum = line;
				}
			}
		}
		catch (IOException e) {}
 
		return strNum;
	}
}
