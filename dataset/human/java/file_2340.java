import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);

		String ref = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

		while(true){
			int n = stdIn.nextInt();
			if(n==0){
				return;
			}
			int[] k = new int[n];
			for(int i=0;i<n;i++){
				k[i] = stdIn.nextInt();
			}
			stdIn.nextLine();		// 空回し
			String s = stdIn.nextLine();
			String ans = "";
			int idx = -1;
			for(int i=0;i<s.length();i++){
				if(++idx==n) idx = 0;
				char nowChar = s.charAt(i);
				int nowIdx = ref.indexOf(nowChar);
				int nextIdx = nowIdx-k[idx];
				if(nextIdx<0) nextIdx += 52;
				char nextChar = ref.charAt(nextIdx);
				String temp = String.valueOf(nextChar);
				ans += String.valueOf(temp);
			}
			System.out.println(ans);
		}
	}
}
