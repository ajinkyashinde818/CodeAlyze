import java.util.*;
public class Main{
	public static void main(String[]args){
      Scanner scan=new Scanner(System.in);
    	int n=scan.nextInt();
		int flag=0;
		boolean done=false;
		while(n--!=0){
			int a=scan.nextInt();
			int b=scan.nextInt();
			if(a==b)flag++;
			if(flag==3){
				done=true;
			}
			if(a!=b)flag=0;
		}
		if(!done)
		System.out.println("No");
		else
		System.out.println("Yes");
    }	
  
}
