import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
 
public class Main {
 
	public static void main(String[] args) {
		
		
		Scanner sc = new Scanner(System.in);
		
		Integer A = sc.nextInt();
		Integer B = sc.nextInt();
		Integer K = sc.nextInt();
		
		List<Integer>e=new ArrayList<>();
		
		
		for(int i= 1; i<=Math.max(A, B); i++){
			if(A%i==0&&B%i==0){
				e.add(i);
			}
		}
		
		System.out.println(e.get(e.size()-K));
 
	}
 
 
}
