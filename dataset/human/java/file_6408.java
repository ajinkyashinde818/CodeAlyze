import java.util.Scanner;
public class Main {

    public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
    	// 入力
    	int k = sc.nextInt();
    	int s = sc.nextInt();

    	int cnt = 0;

    	for (int x = 0; x <= k; x++){
        	for (int y = 0; y <= k; y++){
        		if((s - (x + y)) >= 0 && (s - (x + y)) <= k){
            		cnt++;
            	}
        	}
    	}

    	// 出力
    	System.out.println(cnt);
    }
}
