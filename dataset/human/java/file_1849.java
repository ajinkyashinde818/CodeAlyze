import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Set;
import java.util.concurrent.atomic.AtomicInteger;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String[] dg = br.readLine().split(" ");
		int d = Integer.parseInt(dg[0]);
		int g = Integer.parseInt(dg[1]);

		HashMap<Integer, String[]> map = new HashMap<Integer, String[]>();
		for (int i = 0; i < d; i++) {
			map.put(new Integer((i + 1) * 100), br.readLine().split(" "));
		}

		AtomicInteger min = new AtomicInteger(99999);

		defs(map, g, 0, min);

		System.out.println(min.get());

	}

	public static void defs(HashMap<Integer, String[]> map, int g, int count, AtomicInteger min) {
		Set<Integer> set = map.keySet();
		for (Integer point : set) {
			int gc = g;
			int countc = count;
			String[] pointinfo = map.get(point);
			int monsuu = Integer.parseInt(pointinfo[0]);
			int bonus = Integer.parseInt(pointinfo[1]);
			if (monsuu * point + bonus < gc) {
				gc -= monsuu * point + bonus;
				countc += monsuu;
			} else {
				for (int i = 0; i < monsuu; i++) {
					gc -= point;
					countc++;
					if (min.get() <= countc) {
						continue;
					}
					if (gc <= 0) {
						if (countc < min.get()) {
							min.set(countc);
						}
						continue;
					}
				}
				gc -= bonus;
				if (gc <= 0) {
					if (countc < min.get()) {
						min.set(countc);
					}
					continue;
				}
			}
			HashMap<Integer, String[]> newmap = new HashMap<Integer, String[]>(map);
			newmap.remove(point);
			defs(newmap, gc, countc, min);
		}
	}

}
