import java.io.InputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class MyScanner{
    InputStream stream;
    public MyScanner(){
        stream = System.in;
    }
    
    public long nextInt(){
        long ret = 0;
        try{
            while(true){
                char readed = (char)stream.read();
                if(readed < '0' || readed > '9'){
                    break;
                }
                ret = ret * 10 + (readed - '0');
            }
        }catch(IOException e){
            e.printStackTrace();
        }finally{
            return ret;
        }
    }
}

class Main {
    public static void main(String args[]) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        MyScanner sc = new MyScanner();
        long a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
        if(c <= a + b + 1){
            System.out.println(b + c);
        }else{
            System.out.println(a + b * 2 + 1);
        }
    }
}
