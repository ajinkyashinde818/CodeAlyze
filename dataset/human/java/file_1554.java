import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] in = Stream.of(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		
		List<List<String>> A = new ArrayList<>();
		List<List<String>> B = new ArrayList<>();
		
		for (int i = 0; i < in[0]; i++) {
			List<String> a = Arrays.asList(sc.nextLine().split(""));
			A.add(a);
		}
		
		for (int i = 0; i < in[1]; i++) {
			List<String> b = Arrays.asList(sc.nextLine().split(""));
			B.add(b);
		}
		
		boolean exist = false;
		for (int y = 0; y < A.size(); y++) {
			for (int x = 0; x < A.get(y).size(); x++) {
				if(y+B.size()-1 >= A.size() || x+B.size()-1 >= A.size()) continue;
				
				boolean match = true;
				for (int i = 0; i < B.size(); i++) {
					for (int j = 0; j < B.get(i).size(); j++) {
						if (!(A.get(y+i).get(x+j).equals(B.get(i).get(j)))) match = false;
					}
				}
				if(match) exist = true;
			}
		}	
		
		System.out.println(exist ? "Yes" : "No");		
	}
}
