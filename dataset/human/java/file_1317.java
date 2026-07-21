import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
    	int m = scn.nextInt();
    	char[][] aa = new char[n][n];
    	char[][] bb = new char[m][m];
    	for(int i=0; i<n; i++){
      		String a = scn.next();
      		for(int j=0; j<n; j++){
        		aa[i][j]=a.charAt(j);
      		}
    	}
    	for(int i=0; i<m; i++){
      		String b = scn.next();
      		for(int j=0;j<m;j++){
        		bb[i][j]=b.charAt(j);
      		}
    	}
      	for(int i=0; i<n; i++){
      		for(int j=0; j<n; j++){
        		if(i+m>n || j+m>n){
          			break;
        		}
              	String ans = "Yes";
        		for(int k=0; k<m; k++){
          			for(int l=0; l<m; l++){
            			if(aa[i+k][j+l]!=bb[k][l]){
              				ans = "No";
              				break;
            			}
          			}
        		}
              	if(ans.equals("Yes")){
                  System.out.println(ans);
                  return;
                }
            }
      	}
    	System.out.println("No");
	}
}
