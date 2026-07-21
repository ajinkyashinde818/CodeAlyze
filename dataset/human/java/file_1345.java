import java.util.ArrayList;
import java.util.Scanner;




class Main{


	static	ArrayList<Integer> one ;
	static	ArrayList<Integer> two ;
	static	ArrayList<Integer> three ;
	static	ArrayList<Integer> four ;
	static long pow = 1000000007;
	
	static int n;
	static int m;


	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);			//文字の入力
		n =sc.nextInt();
		m =sc.nextInt();

		
		char[][] amap = new char[n][n];
		char[][] bmap = new char[m][m];
		
		for(int i = 0;i < n;i++){
			amap[i] = sc.next().toCharArray();
		}
		for(int i = 0;i < m;i++){
			bmap[i] = sc.next().toCharArray();
		}
		
		

		for(int i = 0;i <= n-m;i++){
			for(int j = 0;j <= n-m;j++){					//スタートいち
				
				char[][] test = new char[m][m];
				for(int x = 0;x < m;x++){					//mapの切り出し
					for(int y = 0;y < m;y++){
						test[y][x] = amap[y+i][x+j];
					}
				}
				if(check(test,bmap)){
					System.out.println("Yes");
					return;
				}
			}
			
		}
		System.out.println("No");


	}
	
	static boolean check(char[][] test,char[][] bmap){
		
		for(int i = 0;i < m;i++){
			for(int j = 0;j < m;j++){
				if(test[i][j] != bmap[i][j]){
					return false;
				}
			}
		}
		return true;
		
	}
}



class Pair implements Comparable{
	Character from;
	int end;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}
