import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int a = sc.nextInt();
		int b = 0;
		boolean c = false;
		// 文字列の入力
		int[] d = new int[a];
		int[] e = new int[a];
		for(int i = 0; i < a; i++){
			d[i] = sc.nextInt();
			e[i] = sc.nextInt();
			if(d[i] == e[i]){
				b++;
				if(b == 3){
					c = true;
				}
			}else{
				b = 0;
			}
		}
		if(c){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		} 
		
		
	}
}
