import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main{

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String[] temp = scanner.nextLine().split(" ");
		int A = Integer.parseInt(temp[0]);
		int B = Integer.parseInt(temp[1]);
		int K = Integer.parseInt(temp[2]);
		Map<Integer,Integer> ans = new HashMap<Integer,Integer>();


		int defa = 1;
		for(int i = 1; i <= 100; i++) {
			if(A % i == 0 && B % i == 0) {
				if(ans.size() == 0) {
					ans.put(defa, i);
				}else {
					ans.put(defa + 1, i);
					defa++;
				}
			}
		}

		System.out.println(ans.get(ans.size() - K + 1));


	}

}
