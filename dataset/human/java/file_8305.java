import java.util.*;  

public class Main {	
    public static Long gcd(Long x,Long y){
        if(x < y) return gcd(y, x);
        if(y == 0) return x;
        return gcd(y, x % y);
    }
    public static Long lcm(Long x,Long y){                                                              
        return x*y/gcd(x,y);                                                                                                                                                                                                                
    }
    public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		Long a = sc.nextLong();
        Long b = sc.nextLong();
		System.out.println(lcm(a,b));   
	}   
}
