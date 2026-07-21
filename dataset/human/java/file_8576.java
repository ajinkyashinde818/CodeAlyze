import java.util.*;
import java.math.*;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// 整数の入
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		ArrayList<Integer> list = new ArrayList<>();
 
		
		for(int i=1;i<101;i++){
			if(i>a && i >b){
				break;
			}

			if(a%i ==0&&b%i ==0){
				list.add(i);
			}
		}
        // System.out.println(list);
		Collections.reverse(list);


        System.out.println(list.get(k-1));
 
	}
}
