import java.util.Scanner;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    byte a = sc.nextByte();
    short b = sc.nextShort();
    if(a>=10){
      System.out.println(b);
    }else{
      System.out.println(b+(10-a)*100);
    }
  }
}
