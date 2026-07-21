import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		char[][] A = new char[N][N];
		char[][] B = new char[M][M];
		
		for(int i = 0; i < N; i++){
			A[i] = sc.next().toCharArray();
		}
		for(int i = 0; i < M; i++){
			B[i] = sc.next().toCharArray();
		}
		sc.close();
		System.out.println(isMatch(A, B) ? "Yes" : "No");
		
	}
	static boolean isMatch(char[][] a, char[][] b){
		for(int ly = 0; ly < a.length; ly++){
			for(int lx = 0; lx < a.length; lx++){
				if(ly+b.length > a.length || lx+b.length > a.length){
					continue;
				}
				boolean match = true;
				for(int y = 0; y < b.length; y++){
					for(int x = 0; x < b.length; x++){
						if(a[ly+y][lx+x] != b[y][x]){
							match = false;
							break;
						}
					}
					if(!match){
						break;
					}
				}
				if(match){
					return true;
				}
			}
		}
		return false;
	}
}
