import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    boolean isReverse = false;//反転中フラグ
    String s = sc.next();
    StringBuilder sb = new StringBuilder(s);//初期状態
    //最後頭にくっつけるグループとお尻にくっつけるグループを用意する
    StringBuilder sb1 = new StringBuilder("");
    StringBuilder sb2= new StringBuilder("");
    int Q = sc.nextInt();
    int tmp = 0;
    String tmpS;
    for(int i = 0;i<Q;i++){
      if(sc.nextInt()==1){
        isReverse = !isReverse;
      }else{
        tmp=sc.nextInt();
        tmpS=sc.next();
        if(isReverse&&tmp==1){//反転中∧頭につける⇔1番のお尻につける
          sb1.append(tmpS);
        }else if(isReverse&&tmp==2){//反転中∧お尻につける⇔2番のお尻につける
          sb2.append(tmpS);
        }else if(!isReverse&&tmp==1){//正常位∧頭につける⇔2番のお尻につける
          sb2.append(tmpS);
        }else{//正常位∧お尻につける⇔1番のお尻につける
          sb1.append(tmpS);
        }
      }
    }
    //反転回数が偶数ならば、2番をひっくり返したやつ+元の文字列+1番の順につける
    if(!isReverse){
      sb.append(sb1);//元の文字列+1番
      sb2.reverse();//2番反転
      sb2.append(sb);
    System.out.println(sb2);
    }else{
      //反転回数が奇数ならば、1番をひっくり返したやつ+元の文字列をひっくり返したやつ+2番の順につける
      sb.reverse();
      sb1.reverse();
      sb1.append(sb);
      sb1.append(sb2);
     System.out.println(sb1);
    }
  } 
}
