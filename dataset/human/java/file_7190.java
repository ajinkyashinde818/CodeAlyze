import java.util.Scanner;
public class Main {
	public static void main(String args[]) {
		Scanner n = new Scanner(System.in);

		int K = n.nextInt();
		int N = n.nextInt();

		int[] intArray;
		intArray = new int[N];
		for(int i=0 ; i<N ; i++) {
			int A = n.nextInt();
			intArray[i] = A;
		}

		int dis = 0;
		int longDis = intArray[0] + (K - intArray[N-1]) ;

		for(int i=0 ; i<N-1 ; i++) {
			dis = intArray[i+1] - intArray[i];

			if(dis >= longDis) {
				longDis = dis;
			}
		}

		System.out.println(K - longDis);
	}
}
