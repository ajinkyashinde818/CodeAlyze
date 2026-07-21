import java.util.* ;
class Main {
  public static void main(String[] args) {
    
    Scanner scan = new Scanner(System.in);
  	String s = scan.next() ;
    char ch[] = s.toCharArray() ;
    ArrayList<Character> a = new ArrayList<>();
    int count = 0 ;
    for(int i = 0 ; i <3 ;i++){
      if(!a.contains(ch[i])){
        a.add(ch[i]);
      }
    }
    if(a.size() !=3){
      System.out.println("No");
    }else{
      System.out.println("Yes");
    }
  }
}
