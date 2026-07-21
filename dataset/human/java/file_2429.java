import java.util.Scanner;


public class Main {

    public static void main(String[] args) {

    	Main main=new Main();

    	main.run();

    }

    void run() {

    	Scanner sc=new Scanner(System.in);

    	String S=sc.next();

    	int index=S.lastIndexOf("FESTIVAL");


    	String result=S.substring(0,index);

    	System.out.println(result);
    }
}
