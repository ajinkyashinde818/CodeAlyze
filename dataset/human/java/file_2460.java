import java.util.*;

public class Main{

    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	
	int n = sc.nextInt();
	
	
	for(;n>0;n--){
	    int s = (a( sc.next().toCharArray())+ a( sc.next().toCharArray())); 
 	    System.out.println( b(s));
	}

    }
    
    static int a(char[] s){
	int m = 1000;
	int c = 100;
	int x = 10;
	int i = 1;
	
	int p = 1;
	int t=0;
	for(int k=0; k<s.length ; k++){
	    switch(s[k]){
	    case 'm':
		t+=p*m;
		p=1;
		break;
	    case 'c':
		t+=p*c;
		p=1;
		break;
	    case 'x':
		t+=p*x;
		p=1;
		break;
	     case 'i':
		t+=p*i;
		p=1;
		break;
	    default:
		p = Integer.parseInt("" + s[k]);
		break;
	    }
	}

	return t;
    }

    static String b(int t){
	String s = "";

	if( t/1000> 0 ){
	    if( t/1000> 1 ) s+= t/1000;
	    s+= 'm';
	    t%=1000;
	}
	
	if( t/100> 0 ){
	    if( t/100> 1 ) s+= t/100;
	    s+= 'c';
	    t%=100;
	}
	
	if( t/10> 0 ){
	    if( t/10> 1 ) s+= t/10;
	    s+= 'x';
	    t%=10;
	}
	
	if( t > 0 ){
	    if( t > 1 ) s+= t;
	    s+= 'i';
	}

	return s;
	
    }
    
    
}
