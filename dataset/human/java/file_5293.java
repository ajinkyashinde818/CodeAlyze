import java.util.Scanner;

class Main{




	public static void main(String[] args) {





		Scanner sc = new Scanner(System.in);			//文字の入力
		int	x = sc.nextInt();
		if(x < 1200){
			System.out.println("ABC");
		}else{
			System.out.println("ARC");
		}


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
