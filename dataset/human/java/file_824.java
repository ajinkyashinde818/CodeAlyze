import java.util.Scanner;
class Main{
  public static void main(String[] args){
  	
    Scanner scan = new Scanner(System.in);
    
    int n = scan.nextInt();
    int r = scan.nextInt();
    int res = 0;
    int k = 0;
    if(n<10){
     k = 100*(10-n);
     res = r + k;
    }else if(n>=10){
      res = r;
    }
    System.out.println(res);
  }
}
