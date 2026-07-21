import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
    
		// 文字列の入力
		List<String> n = Arrays.asList(sc.next().split(""));
    
		// 出力
		System.out.println(n.contains("9") ? "Yes" : "No");
	}
}
