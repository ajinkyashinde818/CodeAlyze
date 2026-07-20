import java.util.*;
class Main {
	public static void main(String[] args) {
		List<Integer> data = new ArrayList<>(Arrays.asList(14, 5, 3));
		Collections.sort(data);
		System.out.println(data.get(0));
	}
}
