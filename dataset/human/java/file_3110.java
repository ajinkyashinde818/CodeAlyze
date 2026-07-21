import java.util.Scanner;
public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);
	String str = "";	
	while(true){
	    str = scan.next();
	    if(str.equals("#END")){
		return;
	    }else{
		System.out.println(rs(str));
	    }	    
	}
    }
    public static String rs(String str){
	char[] chr = str.toCharArray();
	int cl = chr.length;
	int[][] m = new int[cl][cl];
	String RS = "";
	char[] c_RS = new char[cl/2 + 1];
	int RSl = 0;
	for(int k = 0; k < cl; k++) m[k][0] = 0;
	for(int k = 0; k < cl; k++) m[0][k] = 0;
	
	int i = 1;
	int j = 1;
	for(int split = 1; split < cl; split++){
	    for(int k = 0; k < cl/2 + 1; k++) c_RS[k] = ' ';
	    i = 1;
	    while(i <= split){
		j = 1;
		while(j <= cl - split){
		    if(chr[i-1] == chr[j-1+split]) m[i][j] = m[i-1][j-1] + 1;
		    else m[i][j] = Math.max(m[i-1][j],m[i][j-1]);
		    j++;
		}
		i++;
	    }

	    i--;
	    j--;
	    RSl = m[i][j];
	    if(RSl > RS.length()){
		RS = "";
		while(i > 0 && j > 0){
		    if(m[i][j] == m[i][j-1])j--;
		    else if(m[i][j] == m[i-1][j])i--;
		    else{
			c_RS[m[i][j]] = chr[i-1];
			i--;
			j--;
		    }
		}
		for(int k = 1; k <= RSl; k++){
		  RS += c_RS[k];
		}
	    }
	}
	return RS;
    }
}
