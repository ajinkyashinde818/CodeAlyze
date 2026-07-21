import java.util.*;
    public class Main {
     
    	public static void main(String[] args) {
    			
    		Scanner scan=new Scanner(System.in);
    		
    		String x=scan.next();
    		String y=scan.next();
    		
    		int xx=(int)x.charAt(0);
    		int yy=(int)y.charAt(0);
    		
    		if(xx>yy) {
    			System.out.print(">");
    		}else if (xx<yy) {
    			System.out.print("<");    		
    			}else {
    				System.out.print("=");
    			}
   
    	
  
    				
 
     
    }
    }
// end
