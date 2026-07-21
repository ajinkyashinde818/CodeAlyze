import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int E=in.nextInt(),Y=in.nextInt();
		
		switch(E){
		case 0:
			if(Y<=1911)System.out.println("M"+(Y-1867));
			else if(Y<=1925)System.out.println("T"+(Y-1911));
			else if(Y<=1988)System.out.println("S"+(Y-1925));
			else System.out.println("H"+(Y-1988));
			break;
		
		case 1:
			System.out.println(Y+1867);
			break;
		
		case 2:
			System.out.println(Y+1911);
			break;
		
		case 3:
			System.out.println(Y+1925);
			break;
		
		case 4:
			System.out.println(Y+1988);
			break;
		}
	}
}
