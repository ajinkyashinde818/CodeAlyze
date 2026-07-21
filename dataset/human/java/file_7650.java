import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		try(Scanner sc = new Scanner(System.in)) {

			int n = sc.nextInt();
			long k = sc.nextLong();

			int[] to = new int[n+1];

			for(int i = 1 ; i <= n ; i++ ) {
				to[i] = sc.nextInt();
			}

			long[] latestStep = new long[n+1];

			long j = 0;
			int position = 1;
			boolean calcSkip = true;

			while( j < k ) {

//				System.out.println(j + ":" + position);

				// check this city is already visited?
				if ( calcSkip && latestStep[position] > 0 ) {
					long latest = latestStep[position];
					long step = j - latest;

					long rest = k - j;
					long count = rest / step;

					j+= count * step;

					calcSkip = false;
				}
				else {
					//record current
					latestStep[position] = j;

					//transfer
					position = to[position];

					j++;
				}
			}

			System.out.println(position);

		}
	}


}
