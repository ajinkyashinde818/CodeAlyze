import java.util.*;
 
class Main{
  public static void main(String[] args){
    Scanner scan=new Scanner(System.in);
    int lake=scan.nextInt();
    int home=scan.nextInt();
    int leng[]=new int[home];
    for(int a=0; a<home; a++){
      leng[a]=scan.nextInt();
    }
    int max=0, plus=0, hint=0;
    for(int a=0; a<home-1; a++){
      hint=leng[a+1]-leng[a];
      if(max<hint){
        max=hint;
      }
      plus+=hint;
    }
    hint=lake-leng[home-1]+leng[0];
    if(max<hint){
      max=hint;
    }
    plus+=hint;
    System.out.println(plus-max);
  }
}
