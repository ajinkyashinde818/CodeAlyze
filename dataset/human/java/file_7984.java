import java.util.*;
 
class Main{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    long a = sc.nextInt();
    long b = sc.nextInt();
    
    long low;
    long high;
    
    if (a<b) {
      low = a;
      high = b;
    }
    else {
      low = b;
      high = a;
    }
    
    long highMultipler = high;
    long count = 2;
    while ((highMultipler%low)!=0) {
      highMultipler = high * count;
      count++;
    }
    
    System.out.println(highMultipler);
        
  }
}
