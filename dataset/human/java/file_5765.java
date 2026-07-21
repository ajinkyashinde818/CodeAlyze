import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String[] line=sc.nextLine().split("");
		boolean a=false,b=false,c=false;
		for(int i=0;i<3;i++){
			if(line[i].equals("a")){
				a=true;
			}else if(line[i].equals("b")){
				b=true;
			}else if(line[i].equals("c")){
				c=true;
			}
		}
		if(a&&b&&c){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}
	}
}
