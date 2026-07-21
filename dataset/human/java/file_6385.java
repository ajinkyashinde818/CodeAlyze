import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {


	static int X = 0;
	static int Y = 0;
	static int Z = 0;
	static int answer = 0;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new InputStreamReader(System.in));

		int K = sc.nextInt();
		int S = sc.nextInt();

		sc.close();

		setNumber(K,S);

		execute(K,S);


		System.out.println(answer);

	}

	static void setNumber(int k, int s){
		if(k >= s){
			X = s;
			return;
		} else {
			X = k;
			s = s - k;
			if(k >= s){
				Y = s;
				return;
			} else {
				Y = k;
				Z = s - k;
				return;
			}
		}
	}

	static void execute(int K, int S){
		int check = 0;
		int x = X;
		int y = Y;
		int z = Z;

		for(; x >= Math.ceil((double)S/3); x--){
			for(; y >= z; y--){
				if(x >= y) {
					check = checkCombi(x,y,z);
					if(check == 0) {
						answer += 6;
					} else if(check == 2) {
						answer += 3;
					} else if(check == 3) {
						answer += 1;
					}
				}
				z++;
			}
			Y++;
			y = Y;
			z = Z;
		}
	}

	static int checkCombi(int x,int y,int z){
		if((x == y) && (x == z)){
			return 3;
		} else if ((x == y) || (x == z) || (y == z)){
			return 2;
		} else {
			return 0;
		}
	}

}
