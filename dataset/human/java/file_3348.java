import java.util.Scanner;


public class Main {

    public static void main(String[] args) {

    	Main main=new Main();

    	main.run();

    }

    void run() {

    	Scanner sc=new Scanner(System.in);
    	
    	String S=sc.next();
    	
    	if(S.contains("9")) {
    		System.out.println("Yes");
    	}else {
    		System.out.println("No");
    	}
    }
}
