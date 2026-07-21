import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	private static List<Long> getStrings(Scanner sc, long num) {
		List<Long> stringList = new ArrayList<>();
		while(num>0) {
			long nextInt = sc.nextLong();
			stringList.add(nextInt);
			num--;
		}
		return stringList;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long k = sc.nextLong();
		long n = sc.nextLong();
		List<Long> as = getStrings(sc, n);
		long sum = 0;
		for (int i = 1; i < as.size(); i++) {
			sum+=as.get(i)-as.get(i-1);
		}
		long last = k-as.get(as.size()-1)+as.get(0);
		sum+=last;

		long min = Long.MAX_VALUE;
		for (int i = 1; i < as.size(); i++) {
			long j = sum - (as.get(i)-as.get(i-1));
			if (min>j){
				min = j;
			}
		}
		long p = sum-last;
		if (min>p){
			min = p;
		}
		System.out.println(min);
	}

}
