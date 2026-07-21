import java.io.*;
import java.util.*;

public class Main{
    
    public static void main(String args[]) throws IOException{
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	String s[]=br.readLine().split(" ");

	int num[]=new int[2];

	for(int i=0;i<2;i++){
	    switch(s[i]){
	    case "A":
		num[i]=10;
		break;
	    case "B":
		num[i]=11;
		break;
	    case "C":
		num[i]=12;
		break;
	    case "D":
		num[i]=13;
		break;
	    case "E":
		num[i]=14;
		break;
	    case "F":
		num[i]=15;
		break;
	    }
	}
	if(num[0]>num[1]){
	    System.out.println(">");
	    
	}else if(num[0]<num[1]){
	    System.out.println("<");
	}else{
	    System.out.println("=");
	}
	
    }
    public static void permutation(String q, String ans){
        // Base Case
        if(q.length() <= 1) {
	    //   comb.add(ans + q);
        }
        // General Case
        else {
            for (int i = 0; i < q.length(); i++) {
                permutation(q.substring(0, i) + q.substring(i + 1),
                        ans + q.charAt(i));
            }
        }
    }
}
