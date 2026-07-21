import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

class Main {
	String s;
	String[] d = { "dream", "dreamer", "erase", "eraser" };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Main m = new Main(sc);
		m.solve();
		sc.close();
	}

	Main(Scanner sc) {
		s = sc.next();
	}

	void solve() {
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.offer(0);
		while(q.size()>0){
			int i = q.poll();
			for(int j=0;j<4;j++){
				if(i+d[j].length()>s.length()) continue;
				if(d[j].equals(s.substring(i,i+d[j].length()))){
					if(i+d[j].length()==s.length()){
						System.out.println("YES");
						System.exit(0);
					}
					q.offer(i+d[j].length());
				}
			}
		}
		System.out.println("NO");
	}
}
