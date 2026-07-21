import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
		int[] a = new int[n];
		long[] b = new long[n];
		for(int i = 0 ; i < n ; i++) {
			a[i] = sc.nextInt();
		}
      int i = 1;
      int t = 1;
      
		for(; k >= 0 ; --k , ++t ,i = a[i - 1]) {
          if(b[i - 1] > 0)
				k %= (t - b[i - 1]);
          else
				b[i - 1] = t;
          if(k==0L){
				System.out.println(i);
				return;
			}
        }


	}


}
