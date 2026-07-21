import java.util.Scanner;

public class Main {


	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		int sum = 0;
		if(b-c>0){
			sum=b+c;
		}else{
			if(a+b-c>=0){
				sum=b+c;
			}else{
				sum=a+2*b+1;
			}
		}
		System.out.println(sum);
			
	}

}
