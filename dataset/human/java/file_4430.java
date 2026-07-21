import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		int a=s.nextInt();
		int b=s.nextInt();
		int c=s.nextInt();
		s.close();
		int ct=0;
		for(int i=0;i<c;i++){
			ct++;
			if(b>0){
				b--;
				ct++;
			}else if(a>0){
				a--;
			}else{
				break;
			}
		}
		while(b>0){
			b--;
			ct++;
		}
		System.out.println(ct++);
	}
}
