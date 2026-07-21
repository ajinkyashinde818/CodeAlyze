import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Main {
	static int m;
	static int n;
	static int [] map;
	static List<Integer> list;
	static boolean [] stepExistence;
	public static void main(String[]args){
		Scanner scan = new Scanner (System.in);
		n = scan.nextInt();
		m = scan.nextInt();
		map = new int [n+1];
		list = new ArrayList<Integer>();
		stepExistence = new boolean[n+1];
		for(int i = 0;i < n+1;i++) {
			map[i] = -1;
			stepExistence[i] = true;
		}
		for(int i = 0; i < m;i++) {
			list.add(scan.nextInt());
			stepExistence[list.get(i)] = false;
		}
		map[0] = 1;
		map[1] = 1;
		int ans = downSteps(n);
		System.out.println(ans%1000000007);
	}
	public static int downSteps (int Step) {
		if(map[Step] > -1) {
			return map[Step];
		}
		int nextStep = Step-1;
		int twoDownStep = Step-2;
		int pattern = 0;
		if(stepExistence[nextStep]) {
			pattern = downSteps(nextStep);
			if(stepExistence[twoDownStep]) {
				pattern += downSteps(twoDownStep);
			}
		}else if(stepExistence[twoDownStep]) {
			pattern = downSteps(twoDownStep);
		}
		pattern = pattern % 1000000007;
		map[Step] = pattern;
		return pattern;
	}
}
