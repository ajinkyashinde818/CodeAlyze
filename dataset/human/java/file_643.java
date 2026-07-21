import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int miku = input.nextInt();
		int gumi = input.nextInt();
		
		if(miku>=10) {
			System.out.println(gumi);
		}
		else {
			System.out.println(100*(10-miku)+gumi);
		}
		
	}

}
