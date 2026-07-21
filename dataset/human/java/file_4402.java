import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    int n = sc.nextInt();

    ArrayList<Integer> a = new ArrayList<Integer>(n);
    ArrayList<Integer> b = new ArrayList<Integer>(n);
    ArrayList<Integer> c = new ArrayList<Integer>(n-1);

    
    for (int i=0 ; i<n ; i++){
      a.add(sc.nextInt());
    }
    for (int i=0 ; i<n ; i++){
      b.add(sc.nextInt());
    }
    for (int i=0 ; i<n-1 ; i++){
      c.add(sc.nextInt());
    }

    //処理
    int p = 0;
    
    for (int i=0 ; i<n ; i++){
      p += (int)b.get(a.get(i)-1);

      if(i>0){
        if((int)a.get(i-1) == (int)a.get(i) -1){
          p += (int)c.get((int)a.get(i-1)-1);
        }
      }
    }
    System.out.println(p);
  }
}
