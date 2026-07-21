import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		String str[][] = new String[][]{{"A", "10"}, {"B", "11"}, {"C", "12"},
										{"D", "13"}, {"D", "13"}, {"E", "14"}, 
										{"F", "15"}};
		
				Scanner sn = new Scanner(System.in);
		String x = sn.next();
		String y = sn.next();
		sn.close();
		
		int numX = 0;
		int numY = 0;
		for(int i = 0; i < str.length; i++){
			if(x.equals(str[i][0])){
				numX = Integer.parseInt(str[i][1]);
			}
			if(y.equals(str[i][0])){
				numY = Integer.parseInt(str[i][1]);
			}
		}
		
		if(numX > numY){
			System.out.println(">");
		}else if(numX < numY){
			System.out.println("<");
		}else{
			System.out.println("=");
		}	
	}
}
