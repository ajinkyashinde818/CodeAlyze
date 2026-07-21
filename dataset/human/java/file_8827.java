import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);

	int a = scan.nextInt();
	int b = scan.nextInt();
	int k = scan.nextInt();

	int divide = 1;
	for(int i = 100; i >= 1; i--){
	    if(a % i == 0 && b % i == 0){
		k--;
	    }
	    if(k == 0){
		divide = i;
		break;
	    }
	}

	System.out.println(divide);
    }
}
