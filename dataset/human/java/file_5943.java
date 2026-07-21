import java.util.*;
class Main{
    public static void main(String[] args){
	Scanner stdIn=new Scanner(System.in);
	String S = stdIn.next();
	if(S.contains("a")&&S.contains("b")&&S.contains("c")){
	    System.out.println("Yes");
	}else{
	    System.out.println("No");
	}
    }
}
