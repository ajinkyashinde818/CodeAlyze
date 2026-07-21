import java.io.*;
import java.util.Scanner;
class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner in = new Scanner(System.in);
		int n = 0;
		int r = 0;
		int answer = 0;
		
		while(in.hasNextInt()){
		    n = in.nextInt();
		    r = in.nextInt();
		    if (n>=1 && n<=10) {
		        if(r>=0 && r<=4111){
		            answer = (100)*(10-n) + r;
		            System.out.println(answer);
		        }
		    }else if (n>10){
		        answer=r;
		        System.out.println(answer);
		    } 
		    
		}
	}
}
