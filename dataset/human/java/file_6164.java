import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int K =sc.nextInt();
		int S =sc.nextInt();
		int P =0;
		int Q =0;
		
		for (int X=0; X<K+1; X++){
			for (int Y=0; Y<K+1; Y++){
					P=S-X-Y;
					if(0<=P && P<=K){
					Q++;
					}
			}
		}
			System.out.println(Q);
	}
}
