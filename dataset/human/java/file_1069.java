import java.util.*;
import java.awt.geom.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(true){
			int n = sc.nextInt();
			if(n==0) break;
			
			int[] r = new int[n];
			Point2D.Double[] p = new Point2D.Double[n];
			for(int i=0;i<n;i++){
				p[i] = new Point2D.Double(sc.nextInt(),sc.nextInt());
				r[i] = sc.nextInt();
			}
			
			int m = sc.nextInt();
			
			Point2D.Double t, s;
			Line2D.Double b;
			boolean flag;
			for(int i=0;i<m;i++){
				t = new Point2D.Double(sc.nextInt(),sc.nextInt());
				s = new Point2D.Double(sc.nextInt(),sc.nextInt());
				b = new Line2D.Double(s,t);
				flag = false;
				for(int j=0;j<n;j++){
					if((s.distance(p[j])<r[j] && t.distance(p[j])<r[j]) || b.ptSegDist(p[j])>r[j]);
					else{
						flag = true;
						break;
					}
				}
				if(flag==false) System.out.println("Danger");
				else System.out.println("Safe");
			}
		}	
	}	
}
