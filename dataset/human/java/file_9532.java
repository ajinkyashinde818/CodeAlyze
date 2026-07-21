import java.util.*;

public class Main{
	public static void main(String args[]){
	
		Scanner ob = new Scanner(System.in);
		int N = ob.nextInt();
		int is = 0;

		for(int roll = 1; roll <= N; roll++){
			
			int a = ob.nextInt();
			int b = ob.nextInt();

			if(a == b){
				++is;
			}else{
				is = 0;
			}

			if(is == 3){
				break;
			}
		}
		System.out.println((is == 3) ? "Yes" : "No");
	}
}
