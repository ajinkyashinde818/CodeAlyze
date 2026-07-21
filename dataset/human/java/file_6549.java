import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt(),S=sc.nextInt();
		int count = 0;
		for(int i=0;i<=K;i++) {
			for(int j=0;j<=K;j++) {
				int l=S-i-j;
				//System.out.println(l);
				if(l>=0 && l<=K && i+j+l==S) {
					count++;
				}
			}
		}
		System.out.println(count);


	}
	public static int sample(int n) {
		return n;
	}

}
