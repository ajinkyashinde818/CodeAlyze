import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		String[] a = new String[n];
		String[] b = new String[m];
		for(int i = 0; i < n; i++) {
			a[i] = sc.next();
		}
		for(int i =0; i < m; i++) {
			b[i] = sc.next();
		}
		String result = "初期化";
		int idx = 0;
out:		for(int i = 0;i <= n-m; i++) {
			//System.out.println("テスト" + i + " idx:" + idx + " → " + a[i].indexOf(b[0], idx) );
			idx = a[i].indexOf(b[0], idx);
			if(idx == -1) {
				//System.out.println("test");
				idx = 0;
			}else{
				//System.out.println(n + " " + m);
				if(n == m) {
					result = "Yes";
					break out;
				}
				for(int j = 1; j <= m-1; j++) {
					//System.out.println("i-:" + i + " idx:" + idx + " 比較" + a[i + j].indexOf(b[j], idx) );
					if(a[i + j].indexOf(b[j], idx) == idx);
					else if(a[i + j].indexOf(b[j], idx) == -1) {
						idx = 0;
						break;
					}else{
						i--;
						idx++;
						break;
					}
					if(j == m-1) {
						result = "Yes";
						break out;
					}
				}
				
			}
			if(i == n-m) {
				result = "No";
			}
		}
		System.out.println(result);
	}
}
