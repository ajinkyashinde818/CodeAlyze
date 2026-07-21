import java.util.Scanner;

class Main{

	static char[][] map;
	static int N;
	static int M;
	static boolean flag;
	static int ans;



	public static void main(String[] args) {



		Scanner sc = new Scanner(System.in);			//文字の入力
		String string = sc.next();
		char[] cs = string.toCharArray();
		boolean[] flag =new boolean[3];
		for(int i = 0;i < 3;i++){
			if(cs[i] == 'a'){
				flag[0] = true;
			}else if(cs[i] == 'b'){
				flag[1] = true;
			}else if(cs[i] == 'c'){
				flag[2] = true;
			}
		}
		
		if(flag[0] && flag[1] && flag[2]){
			System.out.println("Yes");
		}else{
			System.out.println("No");

		}




	}


}

class Pair implements Comparable{
	String from;
	int end;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}
