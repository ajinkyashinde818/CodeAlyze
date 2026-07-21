import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.IntStream;

public class Main {
	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);

		long n = stdIn.nextInt();
		long k = stdIn.nextLong();

		Transporter transporter = new Transporter();
		IntStream.rangeClosed(1, (int) n).forEach(i -> transporter.add(i, stdIn.nextLong()));

		System.out.println(transporter.simulate(k));

		stdIn.close();
	}
}

class Transporter {
	private Map<Long, Long> map = new HashMap<>();

	public long simulate(long k) {
		List<Long> periods = period();

		//周期
		long lastNo = periods.get(periods.size()-1);
		long lastIndex = periods.size() -1;
		long firstIndex = getFirstIndex(periods, lastNo);
		long periodNo = lastIndex - firstIndex;

		long distFromPeriod = firstIndex;

		if(k <= distFromPeriod) {
			return move(1, k);
		}

		return move(lastNo, (k-distFromPeriod) % periodNo);

	}

	public long getFirstIndex(List<Long> periods, long no) {
		long index = 0;

		for (Long p : periods) {
			if(p == no) {
				return index;
			}
			index++;
		}
		return -1;

	}

	public long move(long init, long n) {
		for (long i = 0; i < n; i++) {
			init = get(init);
		}

		return init;
	}

	public void add(long start, long end) {
		map.put(start, end);
	}

	public long get(long no) {
		return map.get(no);
	}

	public List<Long> period() {
		List<Long> trajectory = new ArrayList<>();
		Set<Long> set = new LinkedHashSet<>();

		long current = 1;
		trajectory.add(current);
		set.add(current);

		while (true) {
			current = get(current);

			trajectory.add(current);

			if(set.contains(current)) {
				return trajectory;
			}

			set.add(current);

		}
	}
}
