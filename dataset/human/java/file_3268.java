import java.util.*;
public class Main {

	public static void main(String[] args) {
		
		// TODO Auto-generated method stub
		Scanner reader=new Scanner(System.in);
		String N=reader.next();
		if (N.charAt(0)=='9' || N.charAt(1)=='9') {
			System.out.print("Yes");
		}
		else {
			System.out.print("No");
		}
 	}

}
