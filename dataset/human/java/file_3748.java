import java.util.ArrayList;
import java.util.Scanner;

class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.next();
		String y = sc.next();
		int a = 0;
		int b = 0;
		ArrayList array = new ArrayList();
		array.add("A");
		array.add("B");
		array.add("C");
		array.add("D");
		array.add("E");
		array.add("F");
		for (int i = 0; i < 6; i++) {
			if(x.equals(array.get(i))){
				a = i;
				break;
			}
		}
		for (int i = 0; i < 6; i++) {
			if(y.equals(array.get(i))){
				b = i;
				break;
			}
		}
		if(a == b){
			System.out.println("=");
		}else if(a < b){
			System.out.println("<");
		}else if(a > b){
			System.out.println(">");
		}
	}
}
