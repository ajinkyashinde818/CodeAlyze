import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int k=sc.nextInt();
		int s=sc.nextInt();

		int c=0;
		for(int x=0;x<=k;x++) {
			for(int y=0;y<=k;y++) {
				if(x+y==s) {
					c++;
				}else if(s-(x+y)<=k&&x+y<s) {
					c++;
				}


			}
		}
		System.out.println(c);

	}

}
