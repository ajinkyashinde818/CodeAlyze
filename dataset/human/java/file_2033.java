import java.util.*; 
import java.lang.*; 


public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
                int cnt = 0;
                
                long N = scan.nextLong();
                if(N==1){
                   System.out.println(0);
                   System.exit(0);
               }
                
                ArrayList<Integer> a = new ArrayList<>();
                ArrayList<Integer> b = new ArrayList<>();
                
                a.add(2);
                b.add(2);
                a.add(3);
                b.add(3);
                
               for(int n=5; n<=1000000; n+=2){
                   boolean aru = false;
                   for(int i=0;a.get(i)*a.get(i)<=n; i++){
                       if(n % a.get(i)==0){
                           aru = true;
                           break;
                       }
                   }
                   if(aru==false){
                       a.add(n);
                       b.add(n);
                   }         
               }
               boolean OK = true;
               while(OK == true){
                    OK = false;
                    for(int i=0; i<a.size();i++){
                        if(N%a.get(i)==0){
                            N=N/a.get(i);
                            a.set(i,a.get(i) * b.get(i));
                            cnt++;
                            OK = true;
                            break;
                        }                        
                    }
               }
               if(N>1000000){
                   System.out.println(cnt+1);
               }else{
               System.out.println(cnt);
               }
        }
}
