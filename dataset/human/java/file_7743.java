import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		long k = sc.nextLong();

		int a[] = new int[n];
		int time[] = new int[n];

		for(int i = 0; i < n; i++){
			a[i] = sc.nextInt() - 1;
		}

		Arrays.fill(time, -1);
		time[0] = 0;
		int currentTime = 0;
		int loopBegin = -1;
		int loopLength = -1;
		int next = a[0];
		while(true){
			currentTime++;
			if(time[next] == -1){
				time[next] = currentTime;
				next = a[next];
			}
			else {
				loopBegin = next;
				loopLength = currentTime - time[next];
				break;
			}
		}

//		for(int i = 0; i < n; i++){
//			System.out.println(time[i]);
//		}
//		System.out.println("loop begin "+ loopBegin + " loop length "+loopLength);

		int loopBeginTime = time[loopBegin];

		if(k <= loopBeginTime){
			for(int i = 0; i < n; i++){
				if(time[i] == k){
					System.out.println(i + 1);
					return;
				}
			}
		}
		else {
			k -= loopBeginTime;
			k %= loopLength;
//			System.out.println("k = "+k);

			if(k == 0){
				System.out.println(loopBegin + 1);
			}
			else {
				next = a[loopBegin];
				for(int i = 0; i < k - 1; i++){
					next = a[next];
				}

				System.out.println(next + 1);
			}
		}

	}

}
