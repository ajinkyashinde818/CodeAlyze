import java.util.*;
class Main {
	public static void main(String[] args) {
		List<Integer> data = new ArrayList<>(Arrays.asList(87, 24, 3));
		Collections.sort(data);
		System.out.println(data.get(0));
	}
}
