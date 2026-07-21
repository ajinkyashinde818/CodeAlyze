import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
		int[] a = new int[n+1];
		for(int i = 1; i <= n; i++){
			a[i] = sc.nextInt();
		}
		int[] fst = new int[n+1];
		int idx = 1, pnt = 1, tmp;
		long zan = k;
		fst[1] = 1;
		while(zan > 0){
			idx++;
			zan--;
			pnt = a[pnt];
			if(fst[pnt] > 0){
				tmp = idx - fst[pnt];
				zan %= (long)tmp;
				Arrays.fill(fst, 0);
			} else {
				fst[pnt] = idx;
			}
		}
		System.out.println(pnt);
	}
}
