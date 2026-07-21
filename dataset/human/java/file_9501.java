import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力(スペース改行関係なし)
		int n = sc.nextInt();
      	int kaisuu = 0;
      
      
		for(int i = 0 ; i < n ; i++){
        	int n1 = sc.nextInt();
        	int n2 = sc.nextInt();
          
          if(n1==n2){
              kaisuu += 1;
            }else{
            kaisuu = 0;
            }
          
         if(kaisuu ==3){
         	break;
         }
        }

		if(kaisuu ==3){
			// 出力
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}
		
	}
}
