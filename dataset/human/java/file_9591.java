import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int old ;
		boolean ans = false;
		int count = 0;
		for(int i = 0;i < n;++i){
			int d_1 = scan.nextInt();
			int d_2 = scan.nextInt();

			if (d_1 == d_2){
				count++;
				if(count == 3) ans = true;
			}else{
				count = 0;
			}
		}
		System.out.print(ans?"Yes":"No");

	}
}
