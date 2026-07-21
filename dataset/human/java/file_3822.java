import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.SplittableRandom;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
 
/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * 
 */
public class Main
{
    public static void main(String[] args)
    {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class TaskC
    {
        public void solve(int testNumber, FastReader in, PrintWriter out) 
        {
        	
        	String s=in.nextString();
        	StringBuilder sb=new StringBuilder();
        	for(int i=0;i<s.length();i++)
        		if(s.charAt(i)!='x') 
        			sb.append(s.charAt(i));
        	
        	if(!sb.toString().equals(sb.reverse().toString())) out.println(-1);
        	else
        	{
        		int res=0;
        		int i=0;
        		int j=s.length()-1;
        		while(i<j)
        		{
        			if(s.charAt(i)=='x'&&s.charAt(j)!='x')
        			{
        				res++;
        				i++;
        			}
        			else if(s.charAt(i)!='x'&&s.charAt(j)=='x')
        			{
        				res++;
        				j--;
        			}
        			else
        			{
        				i++;
        				j--;
        			}
        		}
        		
        		out.println(res);
        	}
            
        }
    }
 
 
 
    static class FastReader
    {
        private InputStream stream;
        private byte[] buf = new byte[8192];
        private int curChar;
        private int pnumChars;
        private FastReader.SpaceCharFilter filter;
 
        public FastReader(InputStream stream)
        {
            this.stream = stream;
        }
 
        private int pread() 
        {
            if (pnumChars == -1)
            {
                throw new InputMismatchException();
            }
            if (curChar >= pnumChars)
            {
                curChar = 0;
                try
                {
                    pnumChars = stream.read(buf);
                } catch (IOException e) 
                {
                    throw new InputMismatchException();
                }
                if (pnumChars <= 0)
                {
                    return -1;
                }
            }
            return buf[curChar++];
        }
 
        public int nextInt()
        {
            int c = pread();
            while (isSpaceChar(c))
                c = pread();
            int sgn = 1;
            if (c == '-') 
            {
                sgn = -1;
                c = pread();
            }
            int res = 0;
            do
            {
                if (c == ',')
                {
                    c = pread();
                }
                if (c < '0' || c > '9')
                {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = pread();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String nextString()
        {
            int c = pread();
            while (isSpaceChar(c))
                c = pread();
            StringBuilder res = new StringBuilder();
            do 
	{
                res.appendCodePoint(c);
                c = pread();
                } while (!isSpaceChar(c));
            return res.toString();
        }
 
        public long nextLong()
        {
            int c = pread();
            while (isSpaceChar(c))
                c = pread();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = pread();
            }
            long res = 0;
            do
            {
                if (c < '0' || c > '9') 
                {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = pread();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public long[] nextLongArray(int n)
        {
            long[] array = new long[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = nextLong();
            }
            return array;
        }
 
        private boolean isSpaceChar(int c)
        {
            if (filter != null)
            {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }
 
        private static boolean isWhitespace(int c) 
        {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        private interface SpaceCharFilter
        {
            public boolean isSpaceChar(int ch);
 
        }
 
    }
}
