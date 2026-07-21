import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int x=0,y=0,z,cnt=0;
		int k=sc.nextInt();
		int s=sc.nextInt();
		for(x=0;x<=k;x++) {
			for(y=0;y<=k;y++) {
				if(s-(x+y)>=0 && s-(x+y)<=k) {
					cnt++;
				}
			}
		}
		System.out.println(cnt);
	}

}
