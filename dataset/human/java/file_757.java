import java.util.*;
public class Main{
	public static void main(String args[]){
		
		Scanner ob = new Scanner(System.in);
		int N, R, I;

		N = ob.nextInt();
		R = ob.nextInt();

		if(N >= 10){
			I = R;	
		}
		else{
			I = R + 1000 - 100 * N;
		}
		System.out.println(I);
	}
}
