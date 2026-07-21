import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int zoro = 0, max = 0;
		for(int i = 0; i < N; i++) {
			if(sc.nextInt() == sc.nextInt())
				zoro++;
			else
				zoro = 0;
			max = Math.max(zoro, max);
		}
		System.out.println(max >= 3 ? "Yes" : "No");
	}

}
