import java.util.*;
	
		public class Main {
			
			public static void main(String[] args) {		
			
				Scanner sc=new Scanner(System.in);			
				long a=sc.nextInt();
				long b=sc.nextInt();				
				long ebob=1;				
				for(int i=1; i<=b; i++) {
					if((a*i)%b==0) {
						System.out.println(a*i);
						break;

					}					
				}
									
			}
		
	}
