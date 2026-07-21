import java.util.Scanner;

class Main{




	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//文字の入力
		String S = sc.next();
		StringBuilder sb = new StringBuilder(S);
		while(true){

			if(sb.length() == 0){					//文字数が0で完了
				System.out.println("YES");
				return;
			}

			if(sb.length() < 5){					//文字数が5以下はありえない
				System.out.println("NO");
				return;
			}

			if(sb.length() >= 7){
				if(sb.substring(sb.length()-7,sb.length()).equals("dreamer")){
				//	System.out.println("dreamer");
					sb.delete(sb.length()-7,sb.length());
					continue;

				}
			}
			if(sb.length() >= 6){
				if(sb.substring(sb.length()-6,sb.length()).equals("eraser")){
				//	System.out.println("eraser");
					sb.delete(sb.length()-6,sb.length());
					continue;
				}
			}
			if(sb.length() >= 5){
				if(sb.substring(sb.length()-5,sb.length()).equals("dream")){
					sb.delete(sb.length()-5,sb.length());
					continue;
				}else if(sb.substring(sb.length()-5,sb.length()).equals("erase")){
					sb.delete(sb.length()-5,sb.length());
					continue;
				}
			}

			System.out.println("NO");
			return;


		}

	}
}

class Pair implements Comparable{
	int from;
	int end;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}
