import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);

	int n = scan.nextInt();
	if(n % 10 == 9){
	    System.out.println("Yes");
	}else if(n / 10 == 9){
	    System.out.println("Yes");
	}else{
	    System.out.println("No");
	}
    }
}
