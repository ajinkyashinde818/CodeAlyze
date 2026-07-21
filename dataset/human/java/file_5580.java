import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
        Long b = sc.nextLong();
        Long c = sc.nextLong();
		Long [] in = new Long [a];
        for(int i=0;i<a;i++){if(i<b){in[i] = c;}
                             else{if(c<1000000000){in[i] = c+1;}
                                 else{in[i]=c-1;}
                                 }
                            }      
		for(int i=0;i<a;i++){System.out.println(in[i]);}
	}
}
