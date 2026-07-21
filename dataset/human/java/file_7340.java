import java.util.*;
public class Main {

 public static void main(String[] args) {
  Scanner no=new Scanner(System.in);
  String s=no.next();
  int y=s.length()-1;
  int i=y;
  for(i=y;i>=0;i--){
    if(s.charAt(i)=='m'){
      if(i-4<0){
        System.out.println("NO");
      }
      else{
       String r=s.substring(i-4,i+1);
       if(r.equals("dream")){
        i=i-4;
       }
       else{
        System.out.println("NO");
        break;
       }
      }
    }
    else if(s.charAt(i)=='e'){
     if(i-4<0){
       System.out.println("NO");
     }
     else{
      String r=s.substring(i-4,i+1);
      if(r.equals("erase")){
        i=i-4;
      }
     }
    }
    else if(s.charAt(i)=='r'){
     boolean t=false;
     boolean t1=false;
     String r="";
     String r1="";
     if(i-6>=0){
      r=s.substring(i-6,i+1);
      t=true;
     }
     if(i-5>=0){
      r1=s.substring(i-5,i+1);
      t1=true;
     }
      if(t==true&&r.equals("dreamer")){
        i=i-6;
      }
      else if(t1==true&&r1.equals("eraser")){
        i=i-5;
      }
      else{
        System.out.println("NO");
        break;
      }
    }
    else{
      System.out.println("NO");
      break;
    }
  }
  //System.out.println(i);
  if(i==-1){
    System.out.println("YES");
  }
 }

}
