import java.io.*;
import java.util.*;

class Main
{
  public static void main (String[] arg)
  {
    Scanner scan = new Scanner(System.in);
    int count = Integer.parseInt(scan.next()); //回数
    int rateIn = Integer.parseInt(scan.next()); //表示レート
    
    /*
    System.out.println(count);
    System.out.println(rateIn);
    */
    
    int rateOut; //今回のレート
    
    if(count >= 10){
      rateOut = rateIn;
    }
    else{
      rateOut = rateIn + (100 * (10 - count));
    }
    
    System.out.println(rateOut);
    
  }
}
