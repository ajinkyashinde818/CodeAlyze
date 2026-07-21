import java.util.*;
public class Main{
	public static void main(String[] args){
    	Scanner sc=new Scanner(System.in);
    	int n=sc.nextInt(),r=sc.nextInt();
    	int N = 100*Math.max(0, 10-n);
    	System.out.println(r+N);
	}
}
