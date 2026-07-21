import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		boolean isNine = false;
		int n = scan.nextInt();
		int tens = (n / 10) % 10; // (n % 100) / 10
        int ones = n % 10;
        if(tens == 9) {
        	isNine = true;
        	//System.out.println("Yes");
        }
        if(ones == 9) {
        	isNine = true;
        	//System.out.println("Yes");
        }
        if(isNine == true) {
        	System.out.println("Yes");
        }else{
        	System.out.println("No");
        }
		}
}
