import java.util.*;
class Main{
	public static void main(String args[]){
    	Scanner scan = new Scanner(System.in);
      	int c = scan.nextInt();
      	int r = scan.nextInt();
      if(c>=10)
      { 
        System.out.println(r);
      	return;
      }
      	int res = r+100*(10-c);
      	System.out.println(res);
    }
  
}
