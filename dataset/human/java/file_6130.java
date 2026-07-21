import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		int k,s,x,y,z,n;
		n = 0;
		Scanner sc = new Scanner(System.in);
		k = sc.nextInt();
		s = sc.nextInt();
		for(x = 0; x <= k; x++) {
			for(y = 0; y <= k; y++) {
				z = s - x - y;
				if(0 <= z && z <= k) {
					n++;
				}
			}
		}
		System.out.println(n);
		sc.close();
	}
}
