import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String input=scanner.next();
		int length=input.length();

		while(length>0){
			if(length>=7 && input.substring(length-7,length).equals("dreamer")){
				length-=7;
			}else if(length>=6 && input.substring(length-6,length).equals("eraser")){
				length-=6;
			}else if(length>=5 && (input.substring(length-5,length).equals("dream") || input.substring(length-5,length).equals("erase"))){
				length-=5;
			}else{
				System.out.println("NO");
				break;
			}
		}
		if(length==0){
			System.out.println("YES");
		}
		scanner.close();
	}

}
