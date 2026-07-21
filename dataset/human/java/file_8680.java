import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Stream;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] line = Stream.of(sc.nextLine().split(" ", 0)).mapToInt(Integer::parseInt).toArray();
		sc.close();

		Set<Integer> divs = new TreeSet<Integer>();

		Main main = new Main();
		int num_GCD = main.GCD(line[0], line[1]);
		divs = main.searchDiviser(num_GCD);
		Integer[] setnums = new Integer[divs.size()];
		divs.toArray(setnums);

		System.out.println(setnums[setnums.length - line[2]]);

	}

	public int GCD(int num1, int num2) {
		if (num2 == 0) {
			return num1;
		} else {
			return GCD(num2, num1 % num2);
		}
	}

	public Set<Integer> searchDiviser(int num) {
		Set<Integer> divisers = new TreeSet<Integer>();

		int numsPiv = (int) Math.sqrt(num);
		if (numsPiv != 1) {
			divisers.add(1);
			divisers.add(num);
		}else {
			divisers.add(1);
			return divisers;
		}

		for (int i = 2; i <= numsPiv; i++) {
			if (num % i == 0) {
				divisers.add(i);
				divisers.add(num / i);
			}
		}

		return divisers;
	}
}
