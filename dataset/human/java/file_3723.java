import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int X =Integer.parseInt(in.next(), 16);
		int Y =Integer.parseInt(in.next(), 16);
		if(X<Y)System.out.println("<");
		else if(X>Y)System.out.println(">");
		else System.out.println("=");
	}
}
