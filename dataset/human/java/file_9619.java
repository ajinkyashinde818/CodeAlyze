import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner stdIn = new Scanner(System.in);
		int N = stdIn.nextInt();
		int D1[] = new int[N];
		int D2[] = new int[N];
		int ans = 0;
		for(int i = 0; i < N; i++){
			D1[i] = stdIn.nextInt();
			D2[i] = stdIn.nextInt();
		}
		for(int i = 0; i < N - 2; i++){
			if(D1[i] == D2[i] && D1[i+1] == D2[i+1] && D1[i+2] == D2[i+2]){
				ans = 1;
			}
		}
		if(ans == 1){
			System.out.println("Yes");
		}
		else{
			System.out.println("No");
		}
		stdIn.close();
	}
}
