import java.util.*;
import java.io.*;
public class Main{
  
    public static void main(String [] args){
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        int q=sc.nextInt();
        boolean rev=false;
        Deque<Character> deque=new LinkedList<>();
        for(int i=0;i<s.length();i++){
            deque.addLast(s.charAt(i));
        }
        
        for(int i=0;i<q;i++){

            int num=sc.nextInt();

            if(num==1){
                rev=!rev;
            }


            else{

                int p=sc.nextInt();
                char ch=sc.next().charAt(0);
                
                if(p==1){//add at beginning

                    if(!rev){
                        // s=ch+s;
                        deque.addFirst(ch);
                    }
                    else{
                        deque.addLast(ch);
                        // s=s+ch;
                    }
            }

                   else{//add at last
                       
                    if(!rev){
                        // s=s+ch;
                        deque.addLast(ch);
                    }
                    else{
                        deque.addFirst(ch);
                        // s=ch+s;
                    }
                   }
                }
            }
            StringBuilder bs=new StringBuilder("");
            Iterator iterator=deque.iterator();
            while(iterator.hasNext()){
                bs.append(iterator.next());
            }
        if(!rev){
            System.out.println(bs.toString());
        }else{
            System.out.println(bs.reverse().toString());
        }


    }
}
