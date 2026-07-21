import java.util.*;

class Main {
	Scanner sc = new Scanner(System.in);

	public void run() {
		int[] merry=new int[]{1,4,1,4,1,2,1,2};
		while(sc.hasNext()){
			int index=0,max=-1,val=0;
			int[] people=new int[]{sc.nextInt(),
				sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt()
				,sc.nextInt(),sc.nextInt(),sc.nextInt()};
			for(int i=0;i<8;i++){
				int sum=0;
				for(int j=0;j<8;j++){
					sum+=Math.min(merry[(i+j)%8],people[j]);
				}
				if(sum>max){
					index=i;
					max=sum;
					int v=0;
					for(int j=0;j<8;j++){
						v=merry[(i+j)%8]+v*10;
					}
					val=v;
				}else if(sum==max){
					int v=0;
					for(int j=0;j<8;j++){
						v=merry[(i+j)%8]+v*10;
					}
					if(v<val){
						index=i;
						max=sum;
						val=v;
					}
				}
			}
			for(int i=0;i<8;i++){
				pr((i==0?"":" ")+merry[(i+index)%8]);
			}
			ln();
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}

	public static void pr(Object o) {
		System.out.print(o);
	}

	public static void ln(Object o) {
		System.out.println(o);
	}

	public static void ln() {
		System.out.println();
	}
}

class P {
	double x;
	double y;

	P(double _x, double _y) {
		x = _x;
		y = _y;
	}

	public static final P Xunit = new P(1, 0);
	public static final P Yunit = new P(0, 1);

	public static double dot(P a, P b) {
		return a.x * b.x + a.y * b.y;
	}

	public static double cross(P a, P b) {
		return a.x * b.y - a.y * b.x;
	}

	public static boolean isParallel(P a1, P a2, P b1, P b2) {
		return Math.abs(cross(a2.s(a1), b2.s(b1))) < Double.MIN_NORMAL;
	}

	public static boolean isVertical(P a1, P a2, P b1, P b2) {
		return Math.abs(dot(a2.s(a1), b2.s(b1))) < Double.MIN_NORMAL;
	}

	public P a(P a) {
		return new P(x + a.x, y + a.y);
	}

	public P s(P a) {
		return new P(x - a.x, y - a.y);
	}

	public double norm() {
		return Math.sqrt(x * x + y * y);
	}

	public double arg() {
		double s = Math.acos(x / norm());
		return y > 0 ? s : 2 * Math.PI - s;
	}

	public P rotate(double t) {
		return new P(Math.cos(t) * this.x - Math.sin(t) * this.y, Math.sin(t)
				* this.x + Math.cos(t) * this.y);
	}

	public static int ccw(P a, P b, P c) {
		if (P.cross(b.s(a), c.s(a)) > Double.MIN_NORMAL) {
			return 1;
		}
		if (cross(b.s(a), c.s(a)) < -Double.MIN_NORMAL) {
			return -1;
		}
		if (dot(b, c) < -Double.MIN_NORMAL)
			return 2;
		if (b.norm() < c.norm() - Double.MIN_NORMAL)
			return -2;
		return 0;
	}

	@Override
	public boolean equals(Object obj) {
		if (obj instanceof P) {
			P p = (P) obj;
			return x == p.x && y == p.y;
		}
		return false;
	}

	public String toString() {
		return "(" + x + "," + y + ")";
	}
}
