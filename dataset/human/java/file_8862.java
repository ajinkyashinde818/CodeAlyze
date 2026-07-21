import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;


public  class Main  {


	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		int max = A>B ? A:B;
		ArrayList <Integer>Ablock = new ArrayList();
		
			int i = 0;
			int e = 0;
			int counter=0;
			for(i =1; i<=A;i++ ) {
				if(A%i ==0) {
					if(B%i ==0) {
						Ablock.add(i);
						
						}
						
					}
					
				}
			
			Ablock.sort(Comparator.reverseOrder());
			e = Ablock.get(K-1);
			
			
			System.out.println(e);
		
		
		
	}}
