import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		List<Long> numberInfo = new ArrayList<Long>();
		for(int i =0;i <n;i++) {
			if(i ==0) {
				numberInfo.add(sc.nextLong());
				continue;
			}
			numberInfo.add(numberInfo.get(i-1) + sc.nextLong());
		}
		long answer = Long.MAX_VALUE;
		for(int i=0;i <n-1;i++) {
			long sunuke = numberInfo.get(i);
			long arai =  numberInfo.get(numberInfo.size()-1) -sunuke;
			long xy = Math.abs(sunuke-arai);
			if(answer >xy) {
				answer = xy;
			}
		}
		System.out.println(answer);
	}
}
