import java.util.Scanner;

public class Main {
	
    public static void main(String[] args){
        
    Scanner sc = new Scanner(System.in);
    String S = sc.next();
    char[]ss = S.toCharArray();

    int cou = 0;
    for(int i=0; i<2; i++) {
	   if(ss[i]=='9') {
		   cou++;
	   }
    }
    if(cou==0) {
    System.out.println("No");
    }else{
        System.out.println("Yes");
    }
}
}
