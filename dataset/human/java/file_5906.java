import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		// 文字列の入力
		List<String> s = Arrays.asList(sc.next().split(""));
    
		// 出力
		System.out.println(s.contains("a") && s.contains("b") && s.contains("c") 
                           ? "Yes" : "No");
	}
}
