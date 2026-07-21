import java.util.*;

class Main{
    public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		String sin = sc.nextLine();
		if(sin.charAt(0)=='9' || sin.charAt(1)=='9'){
			System.out.println("Yes");
		}
		else{
			System.out.println("No");
		}
    }
}
