import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
	public static void main(String args[]){
		try{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(br.readLine());

			for(int i = 0; i < t; i++){
				int n = Integer.parseInt(br.readLine());
				String str = br.readLine();
				System.out.println(solve(n, str));
			}
		}catch(Exception e){
			System.err.println(e);
		}
	}

	public static int solve(int n, String str){
		String str1 = str.substring(0, 2 * n);
		String str2 = str.substring(2 * n, 4 * n);
		//System.out.println(str1 + "\n" + str2);

		// 各通路を通る必要があるかどうか見る
		boolean routes[][] = new boolean[2][n+1];
		if(str1.charAt(0) == 'Y') routes[0][0] = true;
		for(int i = 1; i < n; i++){
			if(str1.charAt(2*i - 1) == 'Y' || str1.charAt(2*i) == 'Y') routes[0][i] = true;
		}
		if(str1.charAt(2*n-1) == 'Y') routes[0][n] = true;

		if(str2.charAt(0) == 'Y') routes[1][0] = true;
		for(int i = 1; i < n; i++){
			if(str2.charAt(2*i - 1) == 'Y' || str2.charAt(2*i) == 'Y') routes[1][i] = true;
		}
		if(str2.charAt(2*n-1) == 'Y') routes[1][n] = true;

		// 前から見ていく
		int which_first = -1;
		for(int i = 0; i < routes[0].length; i++){
			if(routes[0][i]){
				which_first = 0;
				break;
			}else if(routes[1][i]){
				which_first = 1;
				break;
			}
		}
		// 入れる棚が無いとき
		if(which_first == -1) return n+1;

		int which_last = -1;
		for(int i = routes[0].length - 1; i >= 0; i--){
			if(routes[0][i]){
				which_last = 0;
				break;
			}else if(routes[1][i]){
				which_last = 1;
				break;
			}
		}

		int result = n;
		for(int i = 0; i < routes[0].length; i++){
			if(routes[0][i]) result++;
			if(routes[1][i]) result++;
		}
		// System.out.println(which_first + " " + which_last);
		result += which_first;
		result += which_last;

		//printBoolean(routes);
		return result;
	}

	public static void printBoolean(boolean routes[][]){
		for(int i = 0; i < routes[0].length; i++){
			if(routes[0][i]){
				System.out.print("T");
			}else{
				System.out.print("F");
			}
		}
		System.out.print("\n");
		for(int i = 0; i < routes[0].length; i++){
			if(routes[1][i]){
				System.out.print("T");
			}else{
				System.out.print("F");
			}
		}
	}
}
