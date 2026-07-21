import java.io.*;

class Main {
	public static void main(String args[]) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String buf;

		try {
			while (!(buf = br.readLine()).equals("0")) {
				int n = Integer.parseInt(buf);
				int mat[][] = new int[n][n];
				int sq[][] = new int[n][n];
				int max = 0;
				for (int i=0;i<n;i++) {
					String str = br.readLine();
					for (int j=0;j<n;j++) {
						if (str.charAt(j)=='.') mat[i][j] = 1;
						else mat[i][j] = 0;
					}
					sq[i][0] = mat[i][0];
					if (max<sq[i][0]) max = sq[i][0];
				}
				for (int i=1;i<n;i++) {
					sq[0][i] = mat[0][i];
					if (max<sq[0][i]) max = sq[0][i];
				}
				for (int i=1;i<n;i++) {
					for (int j=1;j<n;j++) {
						if (mat[i][j]==0) {
							sq[i][j] = 0;
						} else {
							int min = (sq[i-1][j]<sq[i][j-1]) ? sq[i-1][j] : sq[i][j-1];
							min = (min<sq[i-1][j-1]) ? min : sq[i-1][j-1];
							sq[i][j] = min+1;
							if (max<sq[i][j]) max = sq[i][j];
						}
					}
				}
				System.out.println(max);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
