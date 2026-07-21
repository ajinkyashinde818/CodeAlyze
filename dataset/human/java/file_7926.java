import java.util.*;

class Main{
	private void compute(){
		Scanner sc = new Scanner(System.in);
		int sum = 0;
		for( int i = 0; i < 10; i++){
			int x =  sc.nextInt();
			sum += x;
		}
		System.out.println(sum);
		}
	
	public static void main(String args[]){
		new Main().compute();
	}
	
}
