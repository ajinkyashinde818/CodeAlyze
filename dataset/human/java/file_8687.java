import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//List<String> list= new ArrayList<String>(Arrays.asList(s.split("")));
		List<Integer> list=new ArrayList<Integer>();
		//Integer[][] array = new Integer[n][m];
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		for(int i=1;101>i;i++) {
			if(a%i==0&&b%i==0) {
				list.add(i);
			}
		}
		Collections.reverse(list);
		System.out.println(list.get(k-1));
	}
}
