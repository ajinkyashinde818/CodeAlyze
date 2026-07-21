import java.util.*;
public class Main{
    public static void main(String[] args){
	new Main().run();
    }

    Scanner kbd = new Scanner(System.in);

    void run(){
	while(kbd.hasNext()){
	    int ans = 0;
	    for(int i=0; i<10; i++){
		ans += kbd.nextInt();
	    }
	    System.out.println(ans);
	}
    }
}
