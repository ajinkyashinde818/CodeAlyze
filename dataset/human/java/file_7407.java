import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		if(a.matches("^((dreamer)|(eraser)|(dream)|(erase))+$")){
			System.out.println("YES");
		}else{
			System.out.println("NO");
		}
	}
}
