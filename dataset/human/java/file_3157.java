import java.util.*;
public class Main{
	public  static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		String a=n+"";
		char b[]=a.toCharArray();
		int temp=0;
		for(int i=0;i<b.length;i++) {
			if(b[i]=='9') {
				temp++;
				break;
			}
		}
		if(temp==0) {	
			System.out.println("No");
			//System.out.println(n+" does not contain 9.");
		}
		else {
			System.out.println("Yes");
			//System.out.println("The one's digit of "+n+" is 9.");
		}
		in.close();
	}
}
