import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
         int n=sc.nextInt();
         int strike=0;
         for(int i=0;i<n;i++) {
        	 int x=sc.nextInt();
        	 int y=sc.nextInt();
        	 if(x==y)strike++;
        	 else strike=0;
        	 if(strike==3) {
        		 System.out.println("Yes");
        		 return;
        	 }
         }
         System.out.println("No");

	}

}
