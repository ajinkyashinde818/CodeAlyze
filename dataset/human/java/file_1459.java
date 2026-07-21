import java.util.*;
 
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        String a[] = new String[n];
        String b[] = new String[m];
        for(int i = 0; i < n; i++){
        	a[i] = sc.next();
        }
        for(int i = 0; i < m; i++){
        	b[i] = sc.next();
        }
        for(int i = 0; i < n - m + 1; i++){
        	for(int j = 0; j < n - m + 1; j++){
                int count = 0;
            	for(int k = 0; k < m; k++){
                	if(a[k + i].substring(j, (j + m)).equals(b[k])){
                    	count++;
                    }else{
                    	break;
                    }
                }
                if(count == m){
                	System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
	}
}
