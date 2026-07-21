import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int k = scan.nextInt();
		int n = scan.nextInt();
		int[] array = new int[200000];

		for(int i=0;i<n;i++) {
			array[i] = scan.nextInt();

		}

		int distance = 0;
		int max = array[0] + (k-array[n-1]);
		for(int i=0;i<n-1;i++) {

			distance = array[i+1] - array[i];
			if(distance >= max) {
				max = distance;
			}
	}
		System.out.println(k-max);

		scan.close();

	}

}
