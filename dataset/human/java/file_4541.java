import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int A=sc.nextInt();
      	int B=sc.nextInt();
      	int C=sc.nextInt();
      	int count=0;
      	boolean eatFlag=true;
      
      	while(eatFlag){
         	if(C>0){
            	C-=1;
              	count++;
              	if(A>0){
                	A-=1;
                } else {
                	if(B>0){
                    	B-=1;
                       	count++;
                    }else{
                    	eatFlag=false;
                    }
                }
            }else{
            	if(B>0){
                	count+=B;
                }
              	eatFlag=false;
            } 
        }
      	System.out.println(count);
    }
}
