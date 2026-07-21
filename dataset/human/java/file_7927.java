import java.util.Scanner;

public class Main{
	
	public static void main(String[] args){
		int data[] = new int[10];
		Scanner scan = new Scanner(System.in);
		for(int i = 0; i < 10; i++){
			data[i] = scan.nextInt();
		}
		int total = 0;
		for(int i = 0; i < 10; i++){
			total = total + data[i];
		}
		System.out.println(total);
	}
}
