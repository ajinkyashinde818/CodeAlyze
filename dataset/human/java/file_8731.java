import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		int b=scan.nextInt();
		int k=scan.nextInt();
		ArrayList<Integer>ans=new ArrayList<Integer>();
		if(a>b){
			for(int i=1;i<a+1;i++){
				if(a%i==0&&b%i==0){
					ans.add(i);
				}
			}
		}else{
			for(int i=1;i<b+1;i++){
				if(a%i==0&&b%i==0){
					ans.add(i);
				}
			}

		}
		System.out.println(ans.get(ans.size()-k));
	}
}
