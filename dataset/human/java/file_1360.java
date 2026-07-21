import java.io.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
      InputStreamReader is = new InputStreamReader(System.in);
      BufferedReader br = new BufferedReader(is);
        
        
        //キーボードから1列目を読み込み
        String str = br.readLine();
        //読み込みを分割
        String[] gazou = str.split(" ",0);
        int n = Integer.parseInt(gazou[0]);
        int m = Integer.parseInt(gazou[1]);
        //aとbの配列を作る
        String[][] a = new String[n][n];
        String[][] b = new String[m][m];
        //配列に代入(a)
        for(int i=0; i<n; i++){
        	String str1 = br.readLine();
        	String[] bunkai = str1.split("",0);
        	for(int j=0; j<n; j++){
        		a[i][j] = bunkai[j];
        	} 
        }
        //配列に代入(b)
        for(int i=0; i<m; i++){
        	String str2 = br.readLine();
        	String[] bunkai = str2.split("",0);
        	for(int j=0; j<m; j++){
        		b[i][j] = bunkai[j];
        	}
        }
        //比較
        for(int i=0; i<n-m+1; i++){
        	for(int j=0; j<n-m+1; j++){
                
        		//bの左上一致の場合
        		if(b[0][0].equals(a[i][j])){
        			//停止して比較開始
                    boolean t = true;
        			for(int l=0; l<m; l++){
        				for(int k=0; k<m; k++){
        					//
        					if(!(b[l][k].equals(a[l+i][k+j]))){t=false;}       					
        				}
        			}
        			//異なるものがなかった場合
                    if(t==true){
        			System.out.println("Yes");
        			System.exit(0);}
        		}
        		
        	}
        }
        //比較して完全になかった場合
        System.out.println("No");
    }
}
