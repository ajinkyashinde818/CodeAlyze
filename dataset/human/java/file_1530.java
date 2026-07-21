import java.util.*;

class Main{
	public static void main(String[] $){
		//入力
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		String[] a = new String[n];
		String[] b = new String[m];
		for(int i = 0; i < n; i++) a[i] = sc.next();
		for(int i = 0; i < m; i++) b[i] = sc.next();
		sc.close();

		//処理
		String ans = "No";
		for(int i = 0; i <= n-m; i++){
			for(int j = 0; j <= n-m; j++){
				boolean f = true;
				for(int x = 0; x < m; x++){
					for(int y = 0; y < m; y++){
						if(a[i+x].charAt(j+y) != b[x].charAt(y)) f = false;
					}
				}
				if(f) ans = "Yes";
			}
		}

		//出力
		System.out.println(ans);
	}
}
