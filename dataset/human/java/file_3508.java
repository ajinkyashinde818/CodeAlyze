import java.util.Scanner;

import javax.sql.rowset.serial.SerialArray;

public class Main {

		public static void main(String[] args){
			
			Scanner sc = new Scanner(System.in);

			
			String X = sc.next();
			String Y = sc.next();

			int x2 = 0;
			if (X.equals("A")){
				x2 = 10;
			}else if(X.equals("B") ){
				x2 = 11;
			}else if(X.equals("C") ){
				x2 = 12;
			}else if(X.equals("D") ){
				x2 = 13;
			}else if(X.equals("E") ){
				x2 = 14;
			}else if(X.equals("F") ){
				x2 = 15;
			}

			int y2 = 0;
			if (Y.equals("A")){
				y2 = 10;
			}else if(Y.equals("B") ){
				y2 = 11;
			}else if(Y.equals("C") ){
				y2 = 12;
			}else if(Y.equals("D") ){
				y2 = 13;
			}else if(Y.equals("E") ){
				y2 = 14;
			}else if(Y.equals("F") ){
				y2 = 15;
			}
	        if(x2 < y2 ){
			    System.out.println("<");
	        }else if(x2 == y2){
			    System.out.println("=");
	        }else{
			    System.out.println(">");
	        }
		}
}
