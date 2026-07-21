//package AtCoder;
import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int r=sc.nextInt();
		if(n<10)
		{
			r+=(100*(10-n));
		}
		System.out.println(r);

	}

}
