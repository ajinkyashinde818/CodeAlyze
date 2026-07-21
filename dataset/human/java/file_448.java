import java.util.*;
class Main{
    public static void main(String[] args){
	Scanner stdIn = new Scanner(System.in);
        int N = stdIn.nextInt();
	int R = stdIn.nextInt();
	int r=0;
	int i=0;
	if(N<10){
	    r=100*(10-N);
	    i=R+r;
	}else{
	    i=R;
	}
	System.out.println(i);
    }
}
