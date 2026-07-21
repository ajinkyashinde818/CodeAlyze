import java.util.*;

public class Main {
	static Test[] tests;
	static int d;
	static int g;

	public static void main (String[] args)  {
		Scanner sc = new Scanner(System.in);
		d = sc.nextInt();
		g = sc.nextInt();
		tests = new Test[d];
		for (int i = 0; i < d; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			tests[i] = new Test(i + 1, a, b);
		}
		System.out.println(getResult(0, 0, 0, 0, 0).count);
	}
	
	static Result getResult(int idx, int count, int point, int rCount, int rPoint) {
		if (point >= g) {
			return new Result(count, point);
		}
		if (idx >= d) {
			for (int i = 1; i <= rCount; i++) {
				if (point + i * rPoint >= g) {
					return new Result(count + i, g);
				}
			}
			return null;
		}
		Result r1 = getResult(idx + 1, count + tests[idx].count, point + tests[idx].getBonus(), rCount, rPoint);
		Result r2 = getResult(idx + 1, count, point, tests[idx].count - 1, tests[idx].getPoint());
		if (r1 == null) {
			return r2;
		} else if (r2 == null) {
			return r1;
		} else {
			if (r2.count < r1.count) {
				return r2;
			} else {
				return r1;
			}
		}
	}
	
	static class Result {
		int count;
		int point;
		
		public Result(int count, int point) {
			this.count = count;
			this.point = point;
		}
		
		public String toString() {
			return "count:" + count + " point:" + point;
		}
	}
	
	static class Test {
		int idx;
		int count;
		int bonus;
		
		public Test(int idx, int count, int bonus) {
			this.idx = idx;
			this.count = count;
			this.bonus = bonus;
		}
		
		public int getBonus() {
			return count * getPoint() + bonus;
		}
		
		public int getPoint() {
			return idx * 100;
		}
	}
}
