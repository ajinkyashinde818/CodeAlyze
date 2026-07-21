import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		int a=s.nextInt();
		int b=s.nextInt();
		int k=s.nextInt();
		s.close();
		int num=100;
		int count=0;
		while(num>0){
			if((a%num==0)&&(b%num==0)){
				count++;
				if(count==k)break;
			}
			num--;
		}
		System.out.println(num);
	}
}
