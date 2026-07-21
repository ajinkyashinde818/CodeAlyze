import java.util.Scanner;

class Main{
	public static void main(String args[]){
		Scanner s=new Scanner(System.in);

		int a=s.nextInt();
		for(int i=0;i<a;i++){
			int d=0;
			for(int k=0; k<2; k++) {
				String b=s.next();
				int temp1=0,temp2=1;
				for(int j=0;j<b.length();j++){
					if(b.charAt(j)=='m'){
						d+=1000*temp2;
						temp2=1;
					}
					else if(b.charAt(j)=='c') {
						d+=100*temp2;
						temp2=1;
					}
					else if(b.charAt(j)=='x') {
						d+=10*temp2;
						temp2=1;
					}
					else if(b.charAt(j)=='i') {
						d+=temp2;
						temp2=1;
					}
					else {
						temp2=(int)b.charAt(j)-'0';
					}
				}
			}
			int g=d;
			if(g/1000>1) {
				System.out.print((int)g/1000+"m");
			}
			else if(g/1000==1) {
				System.out.print("m");
			}
			if(g%1000/100>1) {
				System.out.print((int)g%1000/100+"c");
			}
			else if(g%1000/100==1) {
				System.out.print("c");
			}
			if(g%100/10>1) {
				System.out.print((int)g%100/10+"x");
			}
			else if(g%100/10==1) {
				System.out.print("x");
			}
			if(g%10>1) {
				System.out.print(g%10+"i");
			}
			else if(g%10==1) {
				System.out.print("i");
			}
			System.out.println();
		}
	}
}
