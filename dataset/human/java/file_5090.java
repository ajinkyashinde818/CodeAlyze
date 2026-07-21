import java.util.Scanner;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    StringBuffer s = new StringBuffer(sc.next());
    int q = sc.nextInt();
    
    boolean flg = false;

    StringBuffer pre = new StringBuffer();
    StringBuffer post = new StringBuffer();
       
    for(int j=0;j<q;j++){
      if(sc.nextInt()==1){
        flg = !flg;
      }else{
        if(sc.nextInt()==1){
          if(flg){
            post.append(sc.next());
          }else{
            pre.append(sc.next());
          }
        }else{
          if(flg){
            pre.append(sc.next());
          }else{
            post.append(sc.next());
          }
        }
      }
    }

    if(flg){
      System.out.print(post.reverse());
      System.out.print(s.reverse());
      System.out.print(pre);
    }else{
      System.out.print(pre.reverse());
      System.out.print(s);
      System.out.print(post);

    }
  }
}
