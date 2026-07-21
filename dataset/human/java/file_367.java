import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long xs = sc.nextLong();
		long ys = sc.nextLong();
		long xt = sc.nextLong();
		long yt = sc.nextLong();
		int n= sc.nextInt();
		long[] x = new long[n+2];
		long[] y = new long[n+2];
		long[] r = new long[n+2];
		x[0] = xs;
		x[1] = xt;
		y[0] = ys;
		y[1] = yt;
		r[0] = 0;
		r[1] = 0;
		for(int i=0; i<n; i++){
			x[i+2] = sc.nextLong();
			y[i+2] = sc.nextLong();
			r[i+2] = sc.nextLong();
		}
		sc.close();

		double flen = len(xs, ys, xt, yt, 0, 0);
		double[][] edge = new double[n+2][n+2];
		for(int i=0; i<n+2; i++){
			for(int j=0; j<n+2; j++){
				if(i==j){
					edge[i][j] = 0.0f;
				}else{
					double mlen = len(x[i], y[i], x[j], y[j], r[i], r[j]);
					if(mlen <= flen){
						edge[i][j] = mlen;
					}else{
						edge[i][j] = -1.1f;
					}
				}
			}
		}

		double[] dis = new double[n+2];
		
		dijkstra(edge, 0, dis);
		System.out.printf("%.10f",dis[1]);
	}

	public static double len(long x1, long y1, long x2, long y2, long r1, long r2){
		double md = (double)Math.sqrt((Math.pow((x1 - x2), 2) + Math.pow((y1 - y2), 2)));
		double md2 = md - (double)r1 - (double)r2;
		if(md2 > 0){
			return md2;
		}else{
			return 0.0f;
		}
	}

	public static void dijkstra(double[][] map,int src,double[] distance) {
		int nTown = distance.length;
		boolean[] fixed = new boolean[nTown]; // 最短距離が確定したかどうか
		for (int i=0; i<nTown; i++) { // 各都市について初期化する
			distance[i] = 10000000000000f; // 最短距離の初期値は無限遠
			fixed[i] = false;	// 最短距離はまだ確定していない
		}
		distance[src] = 0;	// 出発地点までの距離を0とする
		while (true) {
			// 未確定の中で最も近い都市を求める
			int marked = minIndex(distance,fixed);
			if (marked < 0) return; // 全都市が確定した場合
			if (distance[marked]==Integer.MAX_VALUE) return; // 非連結グラフ
			fixed[marked] = true; // その都市までの最短距離は確定となる
			for (int j=0; j<nTown; j++) { // 隣の都市(i)について
				if (map[marked][j]>-0.1f && !fixed[j]) { // 未確定ならば
					// 旗の都市を経由した距離を求める
					double newDistance = distance[marked]+map[marked][j];
					// 今までの距離よりも小さければ、それを覚える
					if (newDistance < distance[j]) distance[j] = newDistance;
				}
			}
		}
	}
	// まだ距離が確定していない都市の中で、もっとも近いものを探す
	static int minIndex(double[] distance,boolean[] fixed) {
		int idx=0;
		for (; idx<fixed.length; idx++)	// 未確定の都市をどれか一つ探す
			if (!fixed[idx]) break;
		if (idx == fixed.length) return -1; // 未確定の都市が存在しなければ-1
		for (int i=idx+1; i<fixed.length; i++) // 距離が小さいものを探す
			if (!fixed[i] && distance[i]<distance[idx]) idx=i;
		return idx;
	}

}
