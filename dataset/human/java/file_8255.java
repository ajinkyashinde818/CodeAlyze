import java.util.Scanner;


public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
			
			int S = sc.nextInt();
			int T = sc.nextInt();
			int C =0;
			if(S>T) {
				C=T;
			}else {
				C=S;
			}
			
			
			int l =1;
			for(int i=C;i>1;i--) {
			if(Math.floorMod(S, i)==0) {
					if(Math.floorMod(T, i)==0){
						l=i;
						break;

					}
				}
			}
	
			
			System.out.println((long)S*(long)T/l);
	}	

}
