import java.util.Scanner;

public class Main{

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int n = Integer.parseInt(scan.nextLine());

		String[] value = scan.nextLine().split(" ");
		long[] list = new long[n];
		long[] abslist = new long[n];
		long count = 0;
		long max = 0;
		long min = Long.MAX_VALUE;

		for(int i = 0; i < n; i++) {
			list[i] = Long.parseLong(value[i]);
			if(list[i] < 0) {
				count ++;
			}
			abslist[i] = Math.abs(list[i]);
			max += abslist[i];
			min = Math.min(min, abslist[i]);
		}

		if(count % 2 == 0) {
			System.out.println(max);
		}else {
			System.out.println(max - min * 2);
		}



	}

}
