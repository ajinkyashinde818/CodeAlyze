import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		String[] strArray1= {"a","b","c"};	//答え
		
		Scanner sc = new Scanner(System.in);
		
		String str = sc.next();
		// 文字を配列に格納
		String[] strArray = str.split("");
		
		l1: for(int i=0; i<3;i++) {
			l2: for(int j=0; j<3-i; j++) {
				//if(strArray[i] == strArray1[j]) {
				if(strArray[i].equals(strArray1[j])) {
					strArray1 = remove(strArray1,strArray[i]);
					break l2;
				}
				if(j==2-i) {
					System.out.println("No");
					break l1;
				}
			}
			if(i==2) {
				System.out.println("Yes");
			break l1;
			}
		}
		
		sc.close();

	}

	private static String[] remove(String[] target, String removeStr) {
	    List<String> temp = new ArrayList<>(Arrays.asList(target));
	    temp.remove(removeStr);
	    return temp.toArray(new String[0]);
	}
}
