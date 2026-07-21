import java.util.*;

class Main{
    public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		String line = sc.nextLine();
		String ret = "";
        char cleft = line.charAt(0);
        char cright = line.charAt(2);
		if(cleft==cright){
          System.out.println("=");
		}
		else if(cleft<cright){
		  System.out.println("<");
        }
        else{
		  System.out.println(">");
        }
    }
}
