import java.awt.geom.*;
import java.util.*;

public class Main{
	
	public class Circle{
		Point2D p;
		double r;
		public Circle(Point2D p, double r) {
			this.p = p; this.r = r;
		}
	}
	
	private void doit(){
		Scanner sc = new Scanner(System.in);
		while(true){
			int n = sc.nextInt();
			if(n == 0) break;
			Circle [] cs = new Circle[n];
			for(int i = 0; i < n; i++){
				int x = sc.nextInt();
				int y = sc.nextInt();
				int r = sc.nextInt();
				cs[i] = new Circle(new Point2D.Double(x, y), r);
			}
			int m = sc.nextInt();
			while(m-- > 0){
				int x1 = sc.nextInt();
				int y1 = sc.nextInt();
				int x2 = sc.nextInt();
				int y2 = sc.nextInt();
				boolean issafe = false;
				for(int i = 0; i < n; i++){
					boolean in1 = isin(x1,y1, cs[i]);
					boolean in2 = isin(x2,y2,cs[i]);
					if(in1 && in2){
						issafe = false;
					}
					else if(in1 || in2){
						issafe = true;
						break;
					}
					else{
						Line2D l = new Line2D.Double(new Point2D.Double(x1, y1), new Point2D.Double(x2, y2));
						double dis = l.ptSegDist(cs[i].p);
						if(dis <= cs[i].r){
							issafe = true;
							break;
						}
						else{
							issafe = false;
						}
					}
				}
				if(issafe){
					System.out.println("Safe");
				}
				else{
					System.out.println("Danger");
				}
			}
		}
	}
	
	private boolean isin(int x1, int y1, Circle c) {
		double dis = Point2D.distance(x1, y1, c.p.getX(), c.p.getY());
		if(dis <= c.r){
			return true;
		}
		return false;
	}

	private void debug(Object... o) { System.out.println("debug = " + Arrays.deepToString(o)); }

	public static void main(String[] args) {
		new Main().doit();
	}
}
