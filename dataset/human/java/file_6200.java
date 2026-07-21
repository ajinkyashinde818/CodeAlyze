import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc =new Scanner(System.in);
		int k = sc.nextInt();
		int s = sc.nextInt();
		int cou=0;
		for(int x = 0;x<=k;x++) {
			for(int y = 0; y <= k;y++) {
				if(s-x-y >=0 && s-x-y <=k) {
					cou++;
				}
			}
		}
		System.out.println(cou);
	}

}
