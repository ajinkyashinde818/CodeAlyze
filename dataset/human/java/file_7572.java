import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	Scanner scan = new Scanner(System.in);

	//入力文字列反転
	String S = scan.next();
	StringBuffer sb = new StringBuffer(S);
	String S_r = sb.reverse().toString();

	//比較文字列反転
	String[] d_ = {"dream", "erase", "eraser", "dreamer"};
	String[] dr_ = new String[d_.length];
	for(int i = 0; i < d_.length; i++){
	    StringBuffer db = new StringBuffer(d_[i]);
	    dr_[i] = db.reverse().toString();
	}

	int bool = 1;
	for(int i = 0; i < S_r.length();){
	    int flag = -1;
	    for(int j = 0; j < dr_.length; j++){
		if(S_r.substring(i, i+dr_[j].length()).compareTo(dr_[j]) == 0){
		    i += dr_[j].length();
		    flag = 1;
		    break;
		}
	    }
	    if(flag == -1){
		bool = -1;
		break;
	    }
	}

	if(bool == 1){
	    System.out.println("YES");
	}else{
	    System.out.println("NO");
	}
    }
}
