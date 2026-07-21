import java.util.Scanner;
import java.util.Vector;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		Vector<Integer> vec = new Vector<Integer>();

		for(int i = 1; i <= Math.min(a, b); i++){
			if(a%i == 0 && b%i == 0){
				vec.add(i);
			}
		}

		System.out.println(vec.get(vec.size() - k));
	}

}
