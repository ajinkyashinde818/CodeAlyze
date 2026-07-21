import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();
    int m = scan.nextInt();

    ArrayList<String> a = new ArrayList<String>();
    ArrayList<String> b = new ArrayList<String>();

    for (int i=0;i<n;i++){
      String c = scan.next();
      a.add(c);
    }

    for (int j=0;j<m;j++){
      String d = scan.next();
      b.add(d);
    }

    ArrayList<ArrayList<String>> g = new ArrayList<ArrayList<String>>();

    for (int k=0;k<m;k++){
      String check = b.get(k);
      ArrayList<String> f = find(check,a);
      g.add(f);
    }

    ArrayList<String> h = g.get(0);

    if (h.size() == 0){
      System.out.println("No");
      return;
    }

    for (String q : h){

      String [] ff = q.split("a");
      int line = Integer.parseInt(ff[0]);
      int loc = Integer.parseInt(ff[1]);
      boolean find = true;

      for (int j=1;j<m;j++){
        int next = line+j;
        if (next >= n ){
          find = false;
          break;
        }
        String next1 = next+"a"+loc;
        ArrayList<String> mm = g.get(j);

        boolean contains = false;

        for (String aa: mm){
          if (aa.equals(next1)){
            contains = true;
            break;
          }
        }

        if (contains == false){
          find = false;
          break;
        }

      }

      if (find == true){
        System.out.println("Yes");
        return;
      }
    }

    System.out.println("No");


  }

  static ArrayList<String> find(String a, ArrayList<String> b){
    ArrayList<String> ret = new ArrayList<String>();

    int g = b.size();
    int l = a.length();
    for (int i=0;i<g;i++){
      String m = b.get(i);
      int k = a.length();

      for (int j=0;j<=g-l;j++){
        String sub = m.substring(j,j+l);
        if (sub.equals(a)){
          String message = i + "a" + j;
          ret.add(message);
        }
      }
    }

    return ret;
  }

}
