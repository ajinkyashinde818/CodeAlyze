import java.awt.geom.Point2D;
import java.util.*;
 
public class Main {
    Scanner sc = new Scanner(System.in);
 
    public static void main(String[] args) {
        new Main(); 
    }
 
    public Main() {
    	new aoj0092().doIt();
    }
    class aoj0092{
    	int dp(int n,int a[][]){
    		int result = 0;
    		for(int i = 1;i < n;i++){
				for(int j = 1;j < n;j++){
					if(a[i][j] != 0){
						a[i][j] = Math.min(a[i-1][j-1], Math.min(a[i-1][j],a[i][j-1]))+1;
						result = Math.max(result,a[i][j]);
					}
				}
			}
    		return result;
    	}
    	void doIt(){
    		while(true){
    			int n = sc.nextInt();
    			if(n == 0)break;
    			int a[][] = new int [n][n];
    			for(int i = 0;i < n;i++){
    				String str = sc.next();
    				char ctr[] = str.toCharArray();
    				for(int j = 0;j < n;j++){
    					if(ctr[j] == '.')a[i][j] = 1;
    					else a[i][j] = 0;
    				}
    			}
    			System.out.println(dp(n,a));
    		}
    	}
    }
}
