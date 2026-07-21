import java.util.*;

public class Main{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int times=sc.nextInt();
        Integer[] data1=new Integer[times];
        Integer[] data2=new Integer[times];
        boolean one=false;
        boolean two=false;
      	boolean now=false;
      	boolean result=false;
        for(int i=0;i<times;i++){
          data1[i]=sc.nextInt();
          data2[i]=sc.nextInt();
        }
        for(int i=0;i<times;i++){
          now=(data1[i]==data2[i]);
          if(one&&two&&now){
            result=true;
			break;
          }
	      two=one;
	      one=now;
        }

      if(result)System.out.println("Yes");
      else System.out.println("No");
	}
	
	
}
