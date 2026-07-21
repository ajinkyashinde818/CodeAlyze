import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args){
        FastScanner fsc=new FastScanner();
        int d=fsc.nextInt();
        long g=fsc.nextLong()/100;
        long[][] pc=new long[d][2];
        for(int i=0;i<d;i++){
            pc[i][0]=fsc.nextLong();
            pc[i][1]=fsc.nextLong()/100;
        }
        fsc.close();
        int min=Integer.MAX_VALUE;
        for(int i=0;i<(1<<d);i++){
            long score=0;
            int num=0;
            for(int bit=0;bit<d;bit++){
                if(((1<<bit)&i)!=0){
                    score+=pc[bit][0]*(bit+1)+pc[bit][1];
                    num+=pc[bit][0];
                }
            }
            if(score<g){
                for(int bit=d-1;bit>=0;bit--){
                    if(((1<<bit)&i)!=0) continue;
                    if(g-score>pc[bit][0]*(bit+1)){
                        num+=pc[bit][0];
                        score+=pc[bit][0]*(bit+1);
                    }
                    else{
                        num+=(g-score)/(bit+1);
                        if((g-score)%(bit+1)!=0) num++;
                        break;
                    }
                }
            }
            min=Math.min(min, num);
        }
        System.out.println(min);
    }
    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        private boolean hasNextByte(){
            if(ptr<buflen) return true;
            else{
                ptr = 0;
                try{
                    buflen = in.read(buffer);
                }
                catch(IOException e){
                    e.printStackTrace();
                }
                if(buflen<=0) return false;
            }
        return true;
        }
        private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
        private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
        public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while(isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }
        public long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) throw new NumberFormatException();
            while(true){
                if ('0' <= b && b <= '9') {
                    n *= 10;
                    n += b - '0';
                }
                else if(b == -1 || !isPrintableChar(b)) return minus ? -n : n;
                else throw new NumberFormatException();
                b = readByte();
            }
        }
        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }
        public double nextDouble() { return Double.parseDouble(next());}
        public void close(){
            try{in.close();}
            catch(IOException e){e.printStackTrace();}
        }
    }
}
