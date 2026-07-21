import java.util.*;
class Main{
	
    public static void main(String args[]){
    	Scanner sc=new Scanner(System.in);
    	String a=sc.next();
    	String b =sc.next();
    	int x=0;
    	int y=0;
    	switch(a) {
    	case "A":
    			x=0;
    			break;
    	case "B":
    			x=1;
    			break;
    	case "C":	
    			x=2;
    			break;
    	case "D":	
    			x=3;
    			break;
    	case "E":
    			x=4;
    			break;
    	case "F":
    			x=5;
    			break;
    	}
    	switch(b) {
    	case "A":
    			y=0;
    			break;
    	case "B":
    			y=1;
    			break;
    	case "C":	
    			y=2;
    			break;
    	case "D":	
    			y=3;
    			break;
    	case "E":
    			y=4;
    			break;
    	case "F":
    			y=5;
    			break;
    	}

    	System.out.println(x>y?">":x<y?"<":"=");
    }
}
