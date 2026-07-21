import java.util.*;
import java.util.stream.Collectors;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int minuscount = 0;
		List<Integer> values = new ArrayList<Integer>();
		for(int tmp = 0; tmp < n; tmp++) {
			int v = sc.nextInt();
			if(v < 0) {
				minuscount++;
			}
			values.add(Math.abs(v));
		}
		long result = 0;
		if((n % 2 == 1) && (minuscount % 2 == 0)) {
			for(Integer value : values) {
				result += value;
			}
		}else if((n % 2 == 1) && (minuscount % 2 == 1)) {
			int min = values.stream().min(Comparator.comparing(Integer::valueOf)).orElse(0);
			values.remove(values.indexOf(min));
			for(Integer value : values) {
				result += value;
			}
			result -= min;
		}else if((n % 2 == 0) && (minuscount % 2 == 0)) {
			for(Integer value : values) {
				result += value;
			}
		}else {
			int min = values.stream().min(Comparator.comparing(Integer::valueOf)).orElse(0);
			values.remove(values.indexOf(min));
			for(Integer value : values) {
				result += value;
			}
			result -= min;
		}
		System.out.println(result);	
	}
}
