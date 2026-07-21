import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		String fes = sc.next();
		char[] name = fes.toCharArray();
		int size = fes.length();
		for(int i = 0;i<size-8;i++){
			System.out.print(name[i]);
		}
		
	}
}
