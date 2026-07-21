import java.util.*;

public class Main{
	public static void main(String args[]){
		
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int a=0;
		int length;
		
	
	
	    if(s.contains("eraser")){
		     s= s.replace("eraser","");
	    }
		
		if(s.contains("erase")){
		    s= s.replace("erase","");
			
		}
		
		if(s.contains("dreamer") ){
		 s= s.replace("dreamer","");
		}

		if(s.contains("dream")){
		s= s.replace("dream","");
		}
		
		if(s.equals("")){
			System.out.println("YES");
		}
		
		else{
				System.out.println("NO");
		}
			
		
		
		
		
	
	}
}
