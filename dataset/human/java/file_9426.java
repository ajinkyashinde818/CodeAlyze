import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int s=sc.nextInt();
    int d1=0,d2=0,count=0;
    for(int i=0;i<s;i++){
      d1=sc.nextInt();
      d2=sc.nextInt();
      if(d1==d2){
        count++;
        if(count==3)break;
      }
      else{
        count=0;
      }
      
    }
    if(count>=3)System.out.println("Yes");
    else System.out.println("No");
  }
}
