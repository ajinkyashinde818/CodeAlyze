import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner stdIn=new Scanner(System.in);
		String X=stdIn.next();
		String Y=stdIn.next();
		String a[]={"A","B","C","D","E","F"};
		int z=0;
		if(X.equals(Y))
			System.out.println("=");
		else{
			while(z<6){
				if(X.equals(a[z])){
					System.out.println("<");
					break;
				}
				if(Y.equals(a[z])){
					System.out.println(">");
					break;
				}
				z++;
			}
		}
	}
}
