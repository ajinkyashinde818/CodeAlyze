import java.util.Scanner;

public class Main {
public static void main(String[] args) {
	

		Scanner n =  new Scanner(System.in);
		String N =new String();
		N = n.next();			//個数の入力

		
		String W =new String();
		W = n.next();			//最大の入力

		
		int A = 0;
		int B = 0; 
		
		if(N.equals("A")){
			A = 0;
		}if(N.equals("B")){
			A = 1;
		}if(N.equals("C")){
			A = 2;
		}if(N.equals("D")){
			A = 3;
		}if(N.equals("E")){
			A = 4;
		}if(N.equals("F")){
			A = 5;
		}
		if(W.equals("A")){
			B = 0;
		}if(W.equals("B")){
			B = 1;
		}if(W.equals("C")){
			B = 2;
		}if(W.equals("D")){
			B = 3;
		}if(W.equals("E")){
			B = 4;
		}if(W.equals("F")){
			B = 5;
		}
		
		
		if(A > B){
			System.out.println(">");
		}else if(A < B){
			System.out.println("<");
		}else {
			System.out.println("=");
		}
		
	}
}
