import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;


public class Main {
	private	static	BufferedReader	br = null;

	static {
		br = new BufferedReader(new InputStreamReader(System.in));
	}
 
    /**
     * @param args
     */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MapData	map = null;
		while((map = parseMap()) != null) {
			solve(map);
		}
	}

	private static MapData parseMap() {
		MapData	map = null;
		int		len = parseLen();
	
		if (len > 0) {
			map   = new MapData();
			map.l = new MapLine[len];
			for (int y = 0; y < len; y++) {
				String	strin = null;
		        if ((strin = parseStdin()) != null) {
		        	map.l[y]   = new MapLine();
		        	map.l[y].d = new MapDot[len];
		        	for (int x = 0; x < strin.length(); x++) {
		        		char	c = strin.charAt(x);

		        		map.l[y].d[x]   = new MapDot();
		        		map.l[y].d[x].s = (c == (char)'.') ? 1 : 0;

		        		if (x > 0 && c == (char)'.' && map.l[y].d[x-1].s == 1) {
		        			map.l[y].d[x].w = map.l[y].d[x-1].w;
		        			map.l[y].d[x].w[0]++;
		        		} else {
		        			map.l[y].d[x].w    = new int[2];
		        			if (c == (char)'.') {
		        				map.l[y].d[x].w[0] = 1;
		        			} else {
		        				map.l[y].s.push(x);
		        			}
	        				map.l[y].d[x].w[1] = x;
		        		}

		        		if (y > 0 && c == (char)'.' && map.l[y-1].d[x].s == 1) {
		        			map.l[y].d[x].h = map.l[y-1].d[x].h;
		        			map.l[y].d[x].h[0]++;
		        		} else {
		        			map.l[y].d[x].h    = new int[2];
		        			map.l[y].d[x].h[0] = (c == (char)'.') ? 1 : 0;
	        				map.l[y].d[x].h[1] = y;
		        		}
		        	}
		        }
			}

			map.initRect();
		}

		return map;
	}

	private static void solve(MapData map) {
		int	sqrlen = 0;

		if (map != null) {
			sqrlen = map.getSqrLen();
			for (int y = map.r[0]; y + sqrlen <= map.r[1]; y++) {
        		for (int x = map.r[2]; x + sqrlen <= map.r[3];) {
	        		int	sl = 0;

	        		if (map.l[y].d[x].s == 1) {
	        			int	w   = map.l[y].d[x].w[0] - (x - map.l[y].d[x].w[1]);
	        			int	h   = map.l[y].d[x].h[0] - (y - map.l[y].d[x].h[1]);
		        		int	tmp = Math.min(w,h);

		        		for (;tmp > sqrlen && sl == 0; tmp--) {
			        		if (y + tmp - 1 <= map.r[1] && x + tmp - 1 <= map.r[3]) {
			        			int	fb = -1;
				        		for(int l = 0; l < tmp && fb == -1; l++) {
			        				fb = map.l[y+l].getFirstBlock(x, x + tmp - 1);
				        		}
				        		if (fb == -1) {
			        				sqrlen = tmp;
			        				sl     = tmp;
				        		}
			        		}
		        		}
	        		}

	        		x += (sl == 0) ? 1 : sl;
		        }
			}
		}

		System.out.println(sqrlen);
	}

	private static int parseLen() {
		int		params = 0;
        String	strin  = null;

        if ((strin = parseStdin()) != null) {
        	params = Integer.parseInt(strin);
        }
 
        return params;
	}

	private static String parseStdin() {
        String  stdin = null;
        
        try {
        	String  tmp = br.readLine();
        	if (!tmp.isEmpty()) stdin = tmp;
        }
        catch (IOException e) {}
 
        return stdin;
	}
}

class MapDot{
	public	int		s;
	public	int[]	w;
	public	int[]	h;

	public MapDot() {
		s = 0;
		w = null;
		h = null;
	}
}

class MapLine {
	public	MapDot[]	d;
	public	Stack<Integer>	s;

	public MapLine() {
		d = null;
		s = new Stack<Integer>();
	}

	public int getFirstBlock(int head, int tail) {
		int block = -1;

		for (int l = 0; l < s.size(); l++) {
			int	b = s.get(l);
			if (b > tail) {
				break;
			} if (head <= b && b <= tail) {
				block = b;
				break;
			}
		}

		return block;
	}
}

class MapData {
	public	MapLine[]	l;
	public	int[]		r;

	public	MapData() {
		l = null;
		r = new int[4];
	}

	public void initRect() {
		if (l != null) {
			r[1] = l.length - 1;
			r[3] = l.length - 1;

			// 上
			for (r[0] = 0; r[0] < l.length; r[0]++) {
				if (!l[r[0]].s.isEmpty()) {
					break;
				}
			}

			// 下
			for (r[1] = l.length - 1; r[1] >= 0; r[1]--) {
				if (!l[r[1]].s.isEmpty()) {
					break;
				}
			}

			// 左
			for (r[2] = 0; r[2] < l.length; r[2]++) {
				int	y = 0;
				for (; y < l.length; y++) {
					if (l[y].d[r[2]].s == 0) {
						break;
					}
				}
				if (y != l.length) {
					break;
				}
			}

			// 右
			for (r[3] = l.length - 1; r[3] >= 0; r[3]--) {
				int	y = 0;
				for (; y < l.length; y++) {
					if (l[y].d[r[3]].s == 0) {
						break;
					}
				}
				if (y != l.length) {
					break;
				}
			}
		}
	}

	public int getSqrLen() {
		int	sqrlen = 0;

		if (l != null) {
			if (r[0] != 0) {
				sqrlen = (sqrlen == 0) ? r[0] : Math.max(r[0], sqrlen);
			}

			if (l.length - 1 - r[1] != 0) {
				sqrlen = (sqrlen == 0) ? l.length - 1 - r[1] : Math.max(l.length - 1 - r[1], sqrlen);
			}

			if (r[2] != 0) {
				sqrlen = (sqrlen == 0) ? r[2] : Math.max(r[2], sqrlen);
			}

			if (l.length - 1 - r[3] != 0) {
				sqrlen = (sqrlen == 0) ? l.length - 1 - r[3] : Math.max(l.length - 1 - r[3], sqrlen);
			}
		}

		return sqrlen;
	}
}
