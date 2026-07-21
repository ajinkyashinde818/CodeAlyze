import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int r = sc.nextInt();
		int rating;
		if(n>=10) 
			rating = r;
		else 
			rating = r +100*(10-n);
		
		System.out.println(rating);
	}

}
