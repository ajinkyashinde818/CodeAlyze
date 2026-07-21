import java.util.*;
import java.io.*;
public class Main {
        static public class InputIterator{
          ArrayList<String> inputLine = new ArrayList<String>(1024);
          int index = 0;
          int max;
          InputIterator(){
          	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            while(true){
              String read;
              try{
                read = br.readLine();
              }catch(IOException e){
                read = null;
              }
              if(read != null){
                inputLine.add(read);
              }else{
                break;
              }
            }
            max = inputLine.size();
          }
          public boolean hasNext(){return (index < max);}
          public String next(){
          	if(hasNext()){
              String returnStr = inputLine.get(index);
              index++;
              return returnStr;
            }else{
              throw new IndexOutOfBoundsException("これ以上入力はないよ。");
            }
          }
        }
        
        static InputIterator ii = new InputIterator(); 
        static void myout(Object t){System.out.println(t);}//standard output
        static void myerr(Object t){System.err.println(t);}//standard error
        static String next(){return ii.next();}
        static int nextInt(){return Integer.parseInt(next());}
        static long nextLong(){return Long.parseLong(next());}
        static String[] nextStrArray(){return next().split(" ");}
        static ArrayList<Integer> nextIntArray(){
          ArrayList<Integer> ret = new ArrayList<Integer>();
          String[] input = nextStrArray();
          for(int i = 0; i < input.length; i++){
            ret.add(Integer.parseInt(input[i]));
          }
          return ret;
        }
        static ArrayList<Long> nextLongArray(){
          ArrayList<Long> ret = new ArrayList<Long>();
          String[] input = nextStrArray();
          for(int i = 0; i < input.length; i++){
            ret.add(Long.parseLong(input[i]));
          }
          return ret;
        }
        static char[] nextCharArray(){return mySplit(next());}
        static char[] mySplit(String str){return str.toCharArray();}
        static String kaigyoToStr(String[] list){return String.join("\n",list);}
        static String kaigyoToStr(ArrayList<String> list){return String.join("\n",list);}
        static String hanSpToStr(String[] list){return String.join(" ",list);}
        static String hanSpToStr(ArrayList<String> list){return String.join(" ",list);}
        public static void main(String[] args){
          String[] one = nextStrArray();
          int N = Integer.parseInt(one[0]);
          long K = Long.parseLong(one[1]);
          ArrayList<Integer> list = nextIntArray();
          ArrayList<Integer> roopIndex = new ArrayList<Integer>();
          roopIndex.add(0);
          boolean[] access = new boolean[N];
          int[] no = new int[N];
          Arrays.fill(access, false);
          int count = 0;
          int mae = 0;
          access[0] = true;
          no[0] = 0;
          int roop;
          int roopMae;
          while(true){
            int tugi = list.get(mae) - 1;
            if(!access[tugi]){
              roopIndex.add(tugi);
              access[tugi] = true;
              count++;
              no[tugi] = count;
              mae = tugi;
            }else{
              roop = no[mae] - no[tugi] + 1;
              roopMae = no[tugi];
              break;
            }
            if(count == K){
              myout(tugi + 1);
              return;
            }
          }
          //myerr(no[0] + " " + no[1] + " " + no[2] + " " + no[3]);
          //myerr(roopMae);
          //myerr(roop);
          //myerr(roopIndex);
          K -= roopMae;
          K %= roop;
          K += roopMae;
          myout(roopIndex.get((int)K) + 1);
        }
        //Method addition frame start

        //Method addition frame end
}
