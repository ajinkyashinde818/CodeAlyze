import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int n = sc.nextInt();
			if(n == 0) break;
			int[] wx = new int[n];
			int[] wy = new int[n];
			int[] r  = new int[n];
			for(int i = 0; i < n; i++) {
				wx[i] = sc.nextInt();
				wy[i] = sc.nextInt();
				r[i] = sc.nextInt();
			}
			
			int m = sc.nextInt();
			int[] tx = new int[m];
			int[] ty = new int[m];
			int[] sx = new int[m];
			int[] sy = new int[m];
			for(int i = 0; i < m; i++) {
				tx[i] = sc.nextInt();
				ty[i] = sc.nextInt();
				sx[i] = sc.nextInt();
				sy[i] = sc.nextInt();
			}
			
			IN:for(int i = 0; i < m; i++) {
				for(int j = 0; j < n; j++) {
					if(judgeHitScopeLine(tx[i],ty[i],sx[i],sy[i],wx[j],wy[j],r[j])) {
						System.out.println("Safe");
						continue IN;
					}
				}
				System.out.println("Danger");
			}
		}
	}
	static boolean check(int x, int y, int r, int x1, int y1) {
		return Math.pow(x - x1, 2) + Math.pow(y - y1, 2) < r * r ? true : false;
	}
	static int product(int x1 ,int y1, int x2, int y2) {
		return (( x1 * x2 ) + ( y1 * y2 ));
	}

	static public boolean judgeHitScopeLine(int tx, int ty, int sx, int sy,int x, int y, int r) {
		if(check(x,y,r,tx,ty) && check(x,y,r,sx,sy)) return false;
		if(check(x,y,r,tx,ty) || check(x,y,r,sx,sy)) return true;
		int Vx = tx - sx;
		int Vy = ty - sy;
		int Cx = x - sx;
		int Cy = y - sy;
		int n1,n2,n3;
		
		n1 = product(Vx,Vy,Cx,Cy);
		n2 = product(Vx,Vy,Vx,Vy);
		n3 = product(Cx,Cy,Cx,Cy);
		
		if (n1 < 0 || n1 > n2) {
		    return false;
		}
		return (n3 - (n1 * n1 / n2) <= Math.pow(r, 2)) ? true : false;

	}
	

}
