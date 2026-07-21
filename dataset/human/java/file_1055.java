import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
public class Main {
	private	static	BufferedReader	br = null;

	static {
		br = new BufferedReader(new InputStreamReader(System.in));
	}
 
    /**
     * @param args
     */
	public static void main(String[] args) {
		int			cc = 0;
		int			lc = 0;
		Circle[]	cs = null;
		Line[]		ls = null;

		while ((cc = parseCnt()) != 0) {
			cs = new Circle[cc];
			for (int i = 0; i < cs.length; i++) {
				cs[i] = parseCircle();
			}

			lc = parseCnt();
			ls = new Line[lc];
			for (int i = 0; i < ls.length; i++) {
				ls[i] = parseLine();
				solve(cs, ls[i]);
			}
		}
	}

	private static void solve(Circle[] cs, Line ln) {
		double	dk = 0.0;
		double	xp = 0.0;
		double	yp = 0.0;
		double	sp = 0.0;
		double	ds = 0.0;
		boolean	dg = true;
		Line	lt = null;

		for (int i = 0; i < cs.length && dg; i++) {
			dk = (-1.0)*(ln.da*cs[i].dx+ln.db*cs[i].dy+ln.dc)/(ln.da*ln.dvx+ln.db*ln.dvy);
			sp = (cs[i].dr*cs[i].dr)-(dk*dk);
			if (sp >= 0) {
				xp = cs[i].dx+dk*ln.dvx;
				yp = cs[i].dy+dk*ln.dvy;
				ds = Math.sqrt(sp);
				lt = new Line(xp+ds*ln.dex, yp+ds*ln.dey, xp-ds*ln.dex, yp-ds*ln.dey);

				{
					boolean	i1 = lt.isInner(ln.dxs, ln.dys);
					boolean	i2 = lt.isInner(ln.dxe, ln.dye);

					if (i1 != i2) {
						dg = false;
					} else if (!i1 && !i2) {
						dg = (lt.getDirection(ln.dxs, ln.dys) == lt.getDirection(ln.dxe, ln.dye));
					}
				}
			}
		}

		System.out.println((dg) ? "Danger" : "Safe");
	}

	private static Line parseLine() {
		Line	lin = null;
		String	str = null;

		if ((str = parseStdin()) != null) {
			String[]	lines = str.split(" ");
			lin = new Line(Integer.parseInt(lines[0]), Integer.parseInt(lines[1]), Integer.parseInt(lines[2]), Integer.parseInt(lines[3]));
		}

		return lin;
	}

	private static Circle parseCircle() {
		Circle	cir = null;
		String	str = null;

		if ((str = parseStdin()) != null) {
			String[]	lines = str.split(" ");
			cir = new Circle(Integer.parseInt(lines[0]), Integer.parseInt(lines[1]), Integer.parseInt(lines[2]));
		}

		return cir;
	}

	private static int parseCnt() {
		int		cnt = 0;
		String	str = null;

		if ((str = parseStdin()) != null) {
			cnt = Integer.parseInt(str);
		}

		return cnt;
	}

	private static String parseStdin() {
		String  stdin = null;

		try {
			String  tmp = br.readLine();
			if (tmp != null) {
				if (!tmp.isEmpty()) stdin = tmp;
			}
		}
		catch (IOException e) {}

		return stdin;
	}
}

class Circle {
	public	double	dx = 0.0;
	public	double	dy = 0.0;
	public	double	dr = 0.0;

	public Circle(double x, double y, double r) {
		dx = x;
		dy = y;
		dr = r;
	}
}

class Line {
	public	double	dxs  = 0.0;
	public	double	dys  = 0.0;
	public	double	dxe  = 0.0;
	public	double	dye  = 0.0;
	public	double	dex  = 0.0;
	public	double	dey  = 0.0;
	public	double	dvx  = 0.0;
	public	double	dvy  = 0.0;
	public	double	da   = 0.0;
	public	double	db   = 0.0;
	public	double	dc   = 0.0;
	public	double	dl   = 0.0;
	public	double	dxmn = 0.0;
	public	double	dxmx = 0.0;
	public	double	dymn = 0.0;
	public	double	dymx = 0.0;

	public Line(double xs, double ys, double xe, double ye) {
		dxs  = xs;
		dys  = ys;
		dxe  = xe;
		dye  = ye;
		da   = dye-dys;
		db   = dxs-dxe;
		dc   = (-1.0)*(da*xs+db*ys);
		dl   = Math.sqrt(da*da+db*db);
		dex  = (dxe-dxs) / dl;
		dey  = (dye-dys) / dl;
		dvx  = dey*(-1.0);
		dvy  = dex;
		dxmn = Math.min(dxs, dxe);
		dxmx = Math.max(dxs, dxe);
		dymn = Math.min(dys, dye);
		dymx = Math.max(dys, dye);
	}

	public boolean isInner(double x, double y) {
		return (dxmn <= x && x <= dxmx && dymn <= y && y <= dymx);
	}

	public int getDirection(double x, double y) {
		final	int	D_N = 0;
		final	int	D_U = 1;
		final	int	D_D = 2;
		final	int	D_L = 4;
		final	int	D_R = 8;
				int	dir = D_N;

		dir += (x < dxmn) ? D_L : D_N;
		dir += (x > dxmx) ? D_R : D_N;
		dir += (y < dymn) ? D_U : D_N;
		dir += (y > dymx) ? D_D : D_N;

		return dir;
	}
}
