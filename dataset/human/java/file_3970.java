import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException, Exception{
		BufferedReader st = new BufferedReader(new InputStreamReader(System.in));
		int n = getInt(st);
		int[] a = getIntArry(st);
		int[] b = getIntArry(st);
		int[] c = getIntArry(st);
		int ans = 0;
		int preNo = 0;
		for (int i = 0; i < n; i++) {
			ans = ans + b[a[i]-1];
			if (preNo == 0) {
				preNo = a[i];
			} else if(preNo == a[i]-1) {
				ans = ans + c[a[i]-2];
			}
			preNo = a[i];
			/*
			if (i == n-1 && a[i]-2 >= 0) {
				ans = ans + c[a[i]-2];
				anser(c[a[i]-2]);
			}
			*/
		}
		anser(ans);
	}

	private static int getInt(BufferedReader st) throws Exception, IOException {
		int num = Integer.parseInt(st.readLine());
		return num;
	}

	private static int[] getIntArry(BufferedReader st) throws Exception, IOException {
		String line = st.readLine();
		String[] strData = line.split(" ");
		int[] intData = new int[strData.length];
		for (int i = 0; i < strData.length; i++) {
			intData[i] = Integer.parseInt(strData[i]);
		}
		return intData;
	}

	private static void anser(int num) {
		System.out.println(num);
	}


}
