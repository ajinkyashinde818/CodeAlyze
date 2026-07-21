import java.util.*;

public class Main {

	static final double EPS = 1e-8;

	class Point{
		double x, y;
		Point(double _x, double _y){
			this.x = _x;
			this.y = _y;
		}
		Point add(Point a){
			return new Point(this.x + a.x, this.y + a.y);
		}
		Point sub(Point a){
			return new Point(this.x - a.x, this.y - a.y);
		}
		double abs(){
			return Math.hypot(this.x, this.y);
		}
	}

	double iprod(Point p, Point q){
		return p.x*q.x + p.y*q.y;
	}

	double oprod(Point p, Point q){
		return p.x*q.y - p.y*q.x;
	}

	double distanceLinePoint(Point p1, Point p2, Point q){
		return Math.abs(oprod(p2.sub(p1), q.sub(p1))) / p2.sub(p1).abs();
	}

	double distanceSegmentPoint(Point p1, Point p2, Point q){
		if(iprod(p2.sub(p1), q.sub(p1)) < EPS) return q.sub(p1).abs();
		if(iprod(p1.sub(p2), q.sub(p2)) < EPS) return q.sub(p2).abs();
		return distanceLinePoint(p1,p2,q);
	}

	Point[] Cs;
	double[] Rs;

	void run(){
		Scanner in = new Scanner(System.in);
		for(int n=in.nextInt(); n>0; n = in.nextInt()){
			Cs = new Point[n];
			Rs = new double[n];
			for(int i=0; i<n; i++){
				double x = in.nextDouble(), y = in.nextDouble(), r = in.nextDouble();
				Cs[i] = new Point(x,y);
				Rs[i] = r;
			}
			int m = in.nextInt();
			for(int i=0; i<m; i++){
				double tx = in.nextDouble(), ty = in.nextDouble(),
						sx = in.nextDouble(), sy = in.nextDouble();
				System.out.println(solve(new Point(tx, ty), new Point(sx, sy))?"Danger":"Safe");
			}
		}
	}

	boolean check(Point p, Point q, Point center, double r){
		if((p.sub(center).abs() < r - EPS)^(q.sub(center).abs() < r - EPS)){
			return false;
		}
		if(p.sub(center).abs() < r - EPS){
			return true;
		}
		return distanceSegmentPoint(p,q,center) > r + EPS;
	}

	boolean solve(Point p, Point q){
		for(int i=0; i<Cs.length; i++){
			if(!check(p, q, Cs[i], Rs[i])) return false;
		}
		return true;
	}

	public static void main(String args[]){
		new Main().run();
	}
}
