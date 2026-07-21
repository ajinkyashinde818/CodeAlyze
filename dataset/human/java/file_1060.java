import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class Main {

	int INF = 1 << 28;
	int n, m;
	Wall[] walls;
	P t, o;
	void run() {
		Scanner sc = new Scanner (System.in);
		for(;;) {
			n = sc.nextInt();
			if(n==0) break;
			walls = new Wall[n];
			for(int i=0;i<n;i++) walls[i] = new Wall(sc.nextInt(), sc.nextInt(), sc.nextInt());
			m = sc.nextInt();
			for(int i=0;i<m;i++) {
				t = new P(sc.nextInt(), sc.nextInt());
				o = new P(sc.nextInt(), sc.nextInt());
				boolean f = true;
				for(int j=0;j<n;j++) {
					if(distance(t, o, walls[j])) {
						if(clossC(t, o, walls[j])) {
							f = false;
							break;
						}
					}
				}
				if(!f) System.out.println("Safe");
				else System.out.println("Danger");
			}
			
		}
	}
	boolean distance(P p1, P p2, Wall w) {
		int dx = p2.x-p1.x;
		int dy = p2.y-p1.y;
		int line = dx*w.y - dy*w.x + dy*p1.x - dx*p1.y;
		return line * line <= w.r * w.r * (dx*dx+dy*dy);
	}
	
	boolean clossC(P p1, P p2, Wall w) {
		int dx = p2.x-p1.x;
		int dy = p2.y-p1.y;
		int line1 = dy*(p1.y-w.y) + dx*(p1.x-w.x);
		int line2 = dy*(p2.y-w.y) + dx*(p2.x-w.x);
		boolean isIn1 = w.isIn(p1);
		boolean isIn2 = w.isIn(p2);
		if( isIn1 & isIn2 ) return false;
		if( line1 * line2 <= 0 ) return true;
		
		return isIn1^isIn2;
		
	}

	public static void main(String[] args) {
		new Main().run();
	}
	class P {
		int x, y;
		P (int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	class Wall {
		int x, y, r;
		Wall(int x, int y, int r) {
			this.x = x;
			this.y = y;
			this.r = r;
		}
		boolean isIn(P p) {
			return (p.x-x)*(p.x-x) + (p.y-y)*(p.y-y) < r*r;
		}
	}
}
