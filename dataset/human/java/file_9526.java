import java.util.*;

public class Main{ //クラス名はMain
    public static void main(String[] args) {
			
			Scanner sc = new Scanner(System.in);
			
			// 文字列の入力
			int num = sc.nextInt();
      
      		int[] numbers = new int[num*2];
      		for(int i=0;i<num*2;i++){
              	numbers[i] =sc.nextInt();
            }
			
			/*--------------------------------*/
			String ans = "No";
      		int p = 0;
      		int count = 0;
      
      		for(int i=0;i<num;i++){
              if(numbers[p] == numbers[p+1]){
                count++;
              }else{
                count =0;
              }
              if(count == 3){
                ans ="Yes";
                break;
              }
              p+=2;
            }
      
      		System.out.println(ans);
    }
}
