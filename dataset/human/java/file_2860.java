import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class Main {

	static final int[][] dirpe = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	static final int[][] dirpn = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
	static final int[][] dirpw = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	static final int[][] dirps = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

	static final char[] dirce = {'S', 'E', 'N', 'W'};
	static final char[] dircn = {'E', 'N', 'W', 'S'};
	static final char[] dircw = {'N', 'W', 'S', 'E'};
	static final char[] dircs = {'W', 'S', 'E', 'N'};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = "";

		while (!(line = br.readLine()).equals("0 0")) {
			int w = Integer.parseInt(line.substring(0, line.indexOf(' ')));
			int h = Integer.parseInt(line.substring(line.indexOf(' ') + 1));
			char[][] mazec = new char[h][w];
			int[][] mazei = new int[h][w];

			ArrayDeque<Seeker> queue = new ArrayDeque<Seeker>();

			for (int i = 0; i < h; i++) {
				line = br.readLine();
				for (int j = 0; j < w; j++) {
					mazec[i][j] = line.charAt(j);
					if ("SENW".indexOf(mazec[i][j]) != -1) {
						queue.add(new Seeker(mazec[i][j], new int[]{i, j}));
					}
				}
			}

			int elapse = 0;
			while (queue.size() > 0 && elapse < 180) {

				for (Seeker s : queue) {
					int[][] dirp = null;
					char[] dirc = null;
					switch (s.dir) {
						case 'E':
							dirp = dirpe;
							dirc = dirce;
							break;
						case 'N':
							dirp = dirpn;
							dirc = dircn;
							break;
						case 'W':
							dirp = dirpw;
							dirc = dircw;
							break;
						case 'S':
							dirp = dirps;
							dirc = dircs;
							break;
					}
					for (int i = 0; i < 4; i++) {
						int next_y = s.curr[0] + dirp[i][0];
						int next_x = s.curr[1] + dirp[i][1];
						char next_c = mazec[next_y][next_x];
						if (next_c == '.' || next_c == 'X') {
							//方向転換 & 移動先座標設定
							s.dir = dirc[i];
							s.next[0] = next_y;
							s.next[1] = next_x;
							//優先度上書き
							if (mazei[next_y][next_x] < s.prio()) {
								mazei[next_y][next_x] = s.prio();
							}
							break;
						}
					}
				}
				//移動
				for (Seeker s : queue) {
					if (mazei[s.next[0]][s.next[1]] == s.prio()) {
						mazec[s.curr[0]][s.curr[1]] = '.';
						mazei[s.next[0]][s.next[1]] = 0;
						if (mazec[s.next[0]][s.next[1]] == 'X') {
							s.gone = true;
						} else {
							mazec[s.next[0]][s.next[1]] = s.dir;
							s.curr[0] = s.next[0];
							s.curr[1] = s.next[1];
						}
					}
				}
				//移動(脱出)
				int i = queue.size();
				for (int j = 0; j < i; j++) {
					Seeker s = queue.poll();
					if (!s.gone) {
						queue.offer(s);
					}
				}
				elapse++;
			}
			//結果出力
			if (queue.isEmpty()) {
				System.out.println(elapse);
			} else {
				System.out.println("NA");
			}
		}
	}
}

class Seeker {

	static final int priow = 4;
	static final int prios = 3;
	static final int prioe = 2;
	static final int prion = 1;

	char dir;
	int[] curr;
	int[] next;
	boolean gone;

	Seeker(char dir, int[] curr) {
		this.dir = dir;
		this.curr = curr;
		this.next = new int[2];
	}

	int prio() {
		switch (this.dir) {
			case 'W':
				return priow;
			case 'S':
				return prios;
			case 'E':
				return prioe;
			case 'N':
				return prion;
			default:
				return 0;
		}
	}

}
