import java.util.Scanner;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int n = sc.nextInt();
			if(n==0) {
				break;
			}
			int[] wx = new int[n];
			int[] wy = new int[n];
			int[] r = new int[n];
			for(int i=0;i<n;i++) {
				wx[i] = sc.nextInt();
				wy[i] = sc.nextInt();
				r[i] = sc.nextInt();
			}
			int m = sc.nextInt();
			int[] tx = new int[m];
			int[] ty = new int[m];
			int[] sx = new int[m];
			int[] sy = new int[m];
			for(int i=0;i<m;i++) {
				tx[i] = sc.nextInt();
				ty[i] = sc.nextInt();
				sx[i] = sc.nextInt();
				sy[i] = sc.nextInt();
			}
			for(int i=0;i<m;i++) {
				boolean safe = false;
				for(int j=0;j<n;j++) {
					int ax = wx[j]-tx[i];
					int ay = wy[j]-ty[i];
					int bx = wx[j]-sx[i];
					int by = wy[j]-sy[i];
					int al = ax*ax+ay*ay;
					int bl = bx*bx+by*by;
					if(al>r[j]*r[j] && bl>r[j]*r[j]) { //両方外側のとき
						int cx = bx-ax;
						int cy = by-ay;
						int cl = cx*cx+cy*cy;
						int d = (ax*cy-ay*cx)*(ax*cy-ay*cx)/cl;
						if (d<=r[j]*r[j]) { //直線が円と交差
							if((ax*cx+ay*cy)*(bx*cx+by*cy)<0) { //鋭角三角形の形
								safe = true;
								break;
							}
						}
					}else{
						if(al>r[j]*r[j] || bl>r[j]*r[j]) { //内側と外側
							safe = true;
							break;
						}
					}
				}
				System.out.println(safe ? "Safe" : "Danger");
			}
		}
	}
}
