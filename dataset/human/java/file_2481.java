import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		for(int i=0;i<n;i++){
			String s = "";
			int sum = 0;
			int cp, cq;
			for(int j=0;j<2;j++){
				s = sc.next();
				for(int k=0;k<s.length();k++){
					cq = 1;
					cp = s.codePointAt(k);
					if(cp<58){
						cq = cp - 48;
						k++;
						cp = s.codePointAt(k);
					}
					if(cp==109) sum += cq*1000;
					else if(cp==99) sum += cq*100;
					else if(cp==120) sum += cq*10;
					else if(cp==105) sum += cq;
				}	
			}
			
			cp = 1000;
			cq = 0;
			for(int j=0;j<4;j++){
				cq = sum/cp;
				sum %= cp;
				cp /= 10;
				if(j==0 && cq>1) System.out.print(cq + "m");
				if(j==0 && cq==1) System.out.print("m"); 
				if(j==1 && cq>1) System.out.print(cq + "c");
				if(j==1 && cq==1) System.out.print("c"); 	
				if(j==2 && cq>1) System.out.print(cq + "x");
				if(j==2 && cq==1) System.out.print("x"); 
				if(j==3 && cq>1) System.out.print(cq + "i");
				if(j==3 && cq==1) System.out.print("i"); 
			}
			System.out.println();
			
		}
	}	
}
