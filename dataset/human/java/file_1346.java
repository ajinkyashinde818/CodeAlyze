import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);

	/* 入力 */
	int n = scan.nextInt();
	int m = scan.nextInt();
	String[] a = new String[n];
	String[] b = new String[m];
	for(int i = 0; i < n; i++){
	    a[i] = scan.next();
	}
	for(int i = 0; i < m; i++){
	    b[i] = scan.next();
	}

	int judge = -1;
	out: for(int i = 0; i < n-m+1; i++){
	    for(int j = 0; j < n-m+1; j++){
		/* Bの重ねる初期位置決定 */
		int flag = 1;
		for(int k = 0; k < m; k++){
		    for(int l = 0; l < m; l++){
			/* Bの重ねる位置を移動させていく */
			if(a[i+k].charAt(j+l) != b[k].charAt(l)){
			    flag = -1;
			    break;
			}
		    }
		    if(flag == -1){
			break;
		    }
		}
		if(flag == 1){
		    judge = 1;
		    break out;
		}	
	    }
	}

	if(judge == 1){
	    System.out.println("Yes");
	}else{
	    System.out.println("No");
	}
    }
}
