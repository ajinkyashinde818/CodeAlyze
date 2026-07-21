import java.util.*;
 
public class Main{
	public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    int c = s.nextInt();
    int r = s.nextInt();
    
    int res = (c>10)?r:(r+(100*(10-c)));
    System.out.println(res);
    }
 
	
}
