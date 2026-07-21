import java.util.*;
 
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long N = Long.parseLong(sc.next());
    long R = 0;
    if(N%2==0){
      long subN = N/2;
      boolean escape = false;
      for(int i = 1;!escape;i++){
        if(subN/5!=0){
          R+=subN/5;
          subN=subN/5;
        }else{
          escape = true;
        }
      }
    }
    System.out.println(R);
  }
}
