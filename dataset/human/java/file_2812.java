import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;




public class Main {

    public static void main(String[] args) {

    	Main main=new Main();

    	main.run();

    }

    void run() {
    	Scanner sc=new Scanner(System.in);

    	String[] A=sc.next().split("");
    	String[] B=sc.next().split("");

    	Arrays.sort(A);
    	Arrays.sort(B,Collections.reverseOrder());

    	String strA=conectchar(A);
    	String strB=conectchar(B);

    	if(strA.compareTo(strB)<0) {
    		System.out.println("Yes");
    	}else {
    		System.out.println("No");
    	}
    }

    static String conectchar(String[] str) {

    	StringBuilder result=new StringBuilder();

    	for(int i=0;i<str.length;i++) {
    		result.append(str[i]);
    	}

    	return result.toString();
    }


}
