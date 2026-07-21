import java.util.*;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}

	class Pair{
		long x;
		int y;
		Pair(long x, int y){
			this.x=x;
			this.y=y;
		}
	}
	public void run() {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		ArrayList<Pair> pl = new ArrayList<>();
		for(long i=2; i*i<=n; i++) {
			int cnt=0;
			while(n%i==0) {
				n /= i;
				cnt++;
			}
			pl.add(new Pair(i, cnt));
		}
		if(n != 1) {
			pl.add(new Pair(n, 1));
		}

		int ans = 0;
		for(Pair p : pl) {
			int cnt = p.y;
			int i = 1;
			while(i<=cnt) {
				cnt -= i;
				i++;
				ans++;
			}
		}
		System.out.println(ans);
		sc.close();
	}


}
