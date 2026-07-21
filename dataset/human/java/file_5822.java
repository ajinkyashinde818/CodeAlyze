import java.util.Scanner;

public class Main{

	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);
		String problem = sc.nextLine();

		if(problem.contains("a")&&problem.contains("b")&&problem.contains("c")){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}

	}

}
