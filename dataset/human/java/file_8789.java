import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int A=sc.nextInt();
		int B=sc.nextInt();
		int K=sc.nextInt();
		ArrayList<Integer> d=new ArrayList<Integer>();
		for(int i=Math.max(A, B);i>=1;i--){
			if(A%i==0 && B%i==0) d.add(i);
		}
		//d.forEach(e->System.out.println(e));
		System.out.println(d.get(K-1));
	}

}
