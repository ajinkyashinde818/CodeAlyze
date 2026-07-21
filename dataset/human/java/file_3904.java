import java.util.*;
  
public class Main {
    Scanner sc = new Scanner(System.in);
  
    public static void main(String[] args) {
        new Main(); 
    }
  
    public Main() {
        new aoj2583().doIt();
    }
    class aoj2583{
    	char map[][] = new char[1000][1051];
    	int MAX = 0;
    	void clear(){
    		for(int i = 0;i < 1000;i++){
    			for(int j = 0;j < 1051;j++){
    				map[i][j] = '-';
    			}
    		}
    	}
    	void set(int n){
    		for(int i = 0;i < n;i++){
				String str = sc.next();
				MAX = Math.max(MAX,str.length());
				char ctr[] = str.toCharArray();
				for(int j = 0;j < ctr.length;j++){
					map[i][j] = ctr[j];
					if(ctr[j] == '.')map[i][j] = ' ';
					if(j > 0){
						if(ctr[j] != '.' && ctr[j-1] == '.')map[i][j-1] = '+';
					}
				}
			}
    	}
    	void join(int n){
    		for(int i = 1;i < n;i++){
    			for(int j = 0;j < MAX;j++){
    				if(map[i][j] != '+')continue;
    				int ii = i - 1;
    				while(ii > 0){
    					if(map[ii][j] != ' ')break;
    					else map[ii][j] = '|';
    					ii--;
    				}
    			}
    		}
    	}
    	void doIt(){
    		while(true){
    			int n = sc.nextInt();
    			if(n == 0)break;
    			clear();
    			set(n);
    			join(n);
    			for(int i = 0;i < n;i++){
    				for(int j = 0;j < 1051;j++){
    					if(map[i][j] == '-')break;
    					System.out.print(map[i][j]);
    				}
    				System.out.println();
    			}
    		}
    	}
    }
}
