import java.util.Scanner;
public class Main {

    public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
    	// 入力
    	int a = sc.nextInt();
    	int b = sc.nextInt();
    	int k = sc.nextInt();
    	int i = 0;
    	int cnt=0;

    	for(i = Math.min(a,b); i > 0; i--){
    		if(a % i == 0){
    			if(b % i == 0){
    				cnt++;
    				if(cnt == k){
    					break;
    				}
    			}
    		}
    	}


    	// 出力
    	System.out.println(i);
    }
}
