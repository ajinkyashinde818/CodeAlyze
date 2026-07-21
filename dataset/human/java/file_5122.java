import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        LinkedList<Character> strbf = new LinkedList<Character>();

        for(int i = 0 ; i < str.length() ; i++){
            strbf.addLast(str.charAt(i));
        }

        int q = sc.nextInt();

        boolean flipped = false;

        for(int i = 0 ; i < q ; i++){
            int t = sc.nextInt();
            if(t == 1){
                flipped = !flipped;
            }else{
                int f = sc.nextInt();
                char c = sc.next().charAt(0);

                if((f == 1 && !flipped) || (f == 2 && flipped)){
                    strbf.addFirst(c);
                }else{
                    strbf.addLast(c);
                }
            }
        }

        StringBuilder stb = new StringBuilder();
        while(!strbf.isEmpty()){
            if(!flipped){
                stb.append(strbf.removeFirst());
            }else{
                stb.append(strbf.removeLast());
            }
        }

        System.out.println(stb.toString());
    }
}
