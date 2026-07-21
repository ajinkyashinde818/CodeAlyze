import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long n = Long.parseLong(sc.next());
    Map<Long,Integer> map = getFactor(n);
    long sum = 0;
    int base;
    for(Integer value : map.values()){
      base = 1;
      while(value >= base){
        sum++;
        value-=base;
        base++;
      }
    }
    
    System.out.println(sum);
  }
  
  public static Map<Long,Integer> getFactor(long n){
    Map<Long,Integer> map = new HashMap<>();
    for(long i=2;i*i<=n;i++){
      if(n%i==0){
        int count = 0;
        while(n%i==0){
          count++;
          n/=i;
        }
        map.put(i,count);
      }
    }
    if(n!=1){
      map.put(n,1);
    }
    return map;
  } 
}
