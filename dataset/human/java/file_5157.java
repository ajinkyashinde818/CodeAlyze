import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Scanner;
import java.lang.*;
import java.io.*;
import java.util.*;
import java.lang.Integer;
import java.util.HashMap;

class Main
{
    // driver function to test the above functions
    public static void main(String args[]) throws IOException
    {
        Reader.init(System.in);
        String n = Reader.next();
        int q = Reader.nextInt();
        String[] arr = new String[q];
        for (int i=0; i<q; i++){
            String s =Reader.line();
            arr[i] = s;
        }

        char[] main = n.toCharArray();
        Node head= new Node();
        head.val = 0;
        head.nxt = null;
        head.prev = null;


        Node tracker =new Node();
        for (int i=0; i<main.length; i++){
            Node n1 = new Node();
            n1.val = main[i];
            if (i==0){
                n1.nxt = head;
                n1.prev= head;
                head.nxt= n1;
                head.prev = n1;
                tracker=n1;
            }

            else {
                n1.nxt =head;
                n1.prev=tracker;
                tracker.nxt=n1;
                head.prev=n1;
                tracker=n1;
            }

        }
        boolean op = false;
        for (int i=0; i<q; i++){
            String in = arr[i];
            char[] temp = in.toCharArray();
            if (temp.length==1){
                if (op==true){
                    op=false;
                }

                else{
                    op = true;

                }
            }
            else {
                char pos = temp[2];
                char c = temp[4];

                if ((pos=='2' && op==true)||(pos=='1'&&op==false)){
                    Node n1 = new Node();
                    n1.val = c;


                    Node t2 = new Node();
                    t2 = head.nxt;
                    t2.prev=n1;


                    head.nxt = n1;

                    n1.nxt=t2;
                    n1.prev=head;
                }
                else if ((pos=='1'&&op==true)||(pos=='2'&&op==false)) {
                    Node n1 = new Node();
                    n1.val = c;


                    Node t2 = new Node();
                    t2 = head.prev;
                    t2.nxt=n1;


                    head.prev = n1;

                    n1.nxt=head;
                    n1.prev=t2;
                }
            }
        }
        Node trav = new Node();
        if (op==true){
            trav = head.prev;
        }

        if (op==false){
            trav = head.nxt;
        }

        while (trav!=head){
            if (op==true){
                System.out.print(trav.val);
                trav = trav.prev;
            }

            if (op==false){
                System.out.print(trav.val);
                trav = trav.nxt;
            }
        }



    }

}

class Node{
    char val;
    Node nxt = null;
    Node prev=null;


}



class solu{

}

/** Class for buffered reading int and double values */
class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    /** call this method to initialize reader for InputStream */
    static void init(InputStream input) {
        reader = new BufferedReader(
                new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }

    /** get next word */
    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(
                    reader.readLine() );
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }

    static long nextLong() throws IOException {
        return Long.parseLong( next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }

    static String line() throws IOException {
        return reader.readLine();
    }
}
