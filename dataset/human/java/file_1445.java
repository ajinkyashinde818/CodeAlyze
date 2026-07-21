import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        char[][] base = new char[n][n];
        char[][] child = new char[m][m];
     
        for(int x=0; x<n; x++){
                base[x] = sc.next().toCharArray();
        }
        for(int x=0; x<m; x++){
                child[x] = sc.next().toCharArray();
        }
        
        String ans = "No";
        
        for(int x=0; x<n; x++){
            for(int y=0; y<n; y++){
                if((y+m-1 >= n) || (x+m-1 >= n)){
                    continue;
                }
                
                boolean match = true;
                for(int p=0; p<m; p++){
                    for(int q=0; q<m; q++){
                        if(base[x+p][y+q] != child[p][q]){
                            match = false;
                        }
                    }
                }
                if(match){
                    ans = "Yes";
                }
            }
        }
       
        System.out.println(ans);
	}
}
