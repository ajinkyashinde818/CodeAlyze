import java.util.Scanner;

class Main{

	static	int count = 0;
	public static void main(String[] args) {



		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int ans = 0;
			if(N / 10 == 9 || N % 10  == 9){
				System.out.println("Yes");
				return;

			}
	
		
			
			System.out.println("No");
		


	}

}

class Pair implements Comparable{
	int from;
	int middle;
	int end;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}
