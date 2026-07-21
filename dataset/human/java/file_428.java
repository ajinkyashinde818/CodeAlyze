import java.util.*;

public class Main {

	@SuppressWarnings("resource")
	void run() {

		//
		// 画面入力
		//
		Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();
    	int displayedRate = sc.nextInt();

    	int innerRate = 0;
    	if(10 <= n){
    		innerRate = displayedRate;
    	}else{
    		innerRate = displayedRate + 100*(10-n);
    	}
    	System.out.println(innerRate);

	}
	
    public static void main(String[] args) {
        new Main().run();
    }
}
