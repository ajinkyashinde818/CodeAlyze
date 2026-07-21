import java.util.Scanner;

public class Main {

	static int m;
	static int n;
	static int[] books;

	public static void main(String[] args) {
		doIt();

	}
	static void doIt(){
		Scanner sc = new Scanner(System.in);
		m = sc.nextInt();
		n = sc.nextInt();
		while(0 < m + n){
			books = new int[n];
			for(int i = 0; i < n; i++) books[i] = sc.nextInt();
			int max = 1500000;
			int min = 0;
			int mid = 0;
			while(min < max){
				mid = (max + min) / 2;
				if(check(mid)) max = mid;
				else min = mid + 1;
			}
			System.out.println(max);
			m = sc.nextInt();
			n = sc.nextInt();
		}
	}

	static boolean check(int len){
		boolean ret = false;
		int index = 0;
		int l = 0;
		for(int i = 0; i < m; i++){
			l = len;
			while(0 < l){
				if(books[index] <= l){
					l -= books[index++];
					if(index == n) return 0 <= l? true : false;
				}
				else break;
			}
		}
		return false;
	}

}
