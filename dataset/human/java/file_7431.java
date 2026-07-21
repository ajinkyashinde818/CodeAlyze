import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String args[]) throws IOException{
        BufferedReader buff = null;
        buff = new BufferedReader(new InputStreamReader(System.in));
        String s = buff.readLine();
        s = s.replaceAll("eraser","").replaceAll("erase","").replaceAll("dreamer","").replaceAll("dream","");
        if(s.equals("")){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
    }
}
