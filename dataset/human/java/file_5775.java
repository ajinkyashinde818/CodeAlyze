import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		String a = sc.next();
		// スペース区切りの整数の入力
		// 出力
      if(a.contains("a") &&
        a.contains("b") &&
        a.contains("c") ){
		System.out.println("Yes");
    }else{
      System.out.println("No");
    }
	}
}
