import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());

		int a[] = new int[n];
		int b[] = new int[n];
		int c[] = new int[n - 1];

		String[] tmpArray = br.readLine().split(" ");
		for(int i = 0; i < n; i++){
			a[i] = Integer.parseInt(tmpArray[i]);
		}

		tmpArray = br.readLine().split(" ");
		for(int i = 0; i < n; i++){
			b[i] = Integer.parseInt(tmpArray[i]);
		}

		tmpArray = br.readLine().split(" ");
		for(int i = 0; i < n - 1; i++){
			c[i] = Integer.parseInt(tmpArray[i]);
		}
		int result = 0;

		for(int i = 0; i < n; i++){
			result += b[a[i] - 1];

			if(i >= 1 && a[i] == a[i - 1] + 1){
				result += c[a[i - 1] - 1];
			}
//			System.out.println(result);
		}

		System.out.println(result);
	}

}
