import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.AbstractSet;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Set;
import java.io.IOException;
import java.util.AbstractMap;
import java.io.Writer;
import java.util.Map.Entry;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author GYSHGX868
 */
public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    OutputWriter out = new OutputWriter(outputStream);
    TaskD solver = new TaskD();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.nextInt();
      int k = in.nextInt();
      int l = in.nextInt();
      IndependentSetSystem road = new RecursiveIndependentSetSystem(n);
      for (int i = 0; i < k; i++) {
        int p = in.nextInt() - 1;
        int q = in.nextInt() - 1;
        road.join(p, q);
      }
      IndependentSetSystem railway = new RecursiveIndependentSetSystem(n);
      for (int i = 0; i < l; i++) {
        int p = in.nextInt() - 1;
        int q = in.nextInt() - 1;
        railway.join(p, q);
      }
      Counter<IntIntPair> counter = new Counter<>();
      for (int i = 0; i < n; i++) {
        counter.add(IntIntPair.makePair(road.get(i), railway.get(i)));
      }
      out.print(counter.get(IntIntPair.makePair(road.get(0), railway.get(0))));
      for (int i = 1; i < n; i++) {
        out.print(" " + counter.get(IntIntPair.makePair(road.get(i), railway.get(i))));
      }
      out.printLine();
    }

  }

  static interface IndependentSetSystem {
    boolean join(int first, int second);

    int get(int index);

    interface Listener {
      void joined(int joinedRoot, int root);

    }

  }

  static class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
      writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
      this.writer = new PrintWriter(writer);
    }

    public void print(Object... objects) {
      for (int i = 0; i < objects.length; i++) {
        if (i != 0) {
          writer.print(' ');
        }
        writer.print(objects[i]);
      }
    }

    public void printLine() {
      writer.println();
    }

    public void close() {
      writer.close();
    }

    public void print(long i) {
      writer.print(i);
    }

  }

  static class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private InputReader.SpaceCharFilter filter;

    public InputReader(InputStream stream) {
      this.stream = stream;
    }

    public int read() {
      if (numChars == -1) {
        throw new InputMismatchException();
      }
      if (curChar >= numChars) {
        curChar = 0;
        try {
          numChars = stream.read(buf);
        } catch (IOException e) {
          throw new InputMismatchException();
        }
        if (numChars <= 0) {
          return -1;
        }
      }
      return buf[curChar++];
    }

    public int nextInt() {
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      int res = 0;
      do {
        if (c < '0' || c > '9') {
          throw new InputMismatchException();
        }
        res *= 10;
        res += c - '0';
        c = read();
      } while (!isSpaceChar(c));
      return res * sgn;
    }

    public boolean isSpaceChar(int c) {
      if (filter != null) {
        return filter.isSpaceChar(c);
      }
      return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface SpaceCharFilter {
      boolean isSpaceChar(int ch);

    }

  }

  static class RecursiveIndependentSetSystem implements IndependentSetSystem {
    private final int[] color;
    private final int[] rank;
    private int setCount;
    private IndependentSetSystem.Listener listener;

    public RecursiveIndependentSetSystem(int size) {
      color = new int[size];
      rank = new int[size];
      for (int i = 0; i < size; i++) {
        color[i] = i;
      }
      setCount = size;
    }

    public RecursiveIndependentSetSystem(RecursiveIndependentSetSystem other) {
      color = other.color.clone();
      rank = other.rank.clone();
      setCount = other.setCount;
    }

    public boolean join(int first, int second) {
      first = get(first);
      second = get(second);
      if (first == second) {
        return false;
      }
      if (rank[first] < rank[second]) {
        int temp = first;
        first = second;
        second = temp;
      } else if (rank[first] == rank[second]) {
        rank[first]++;
      }
      setCount--;
      color[second] = first;
      if (listener != null) {
        listener.joined(second, first);
      }
      return true;
    }

    public int get(int index) {
      int start = index;
      while (color[index] != index) {
        index = color[index];
      }
      while (start != index) {
        int next = color[start];
        color[start] = index;
        start = next;
      }
      return index;
    }

  }

  static class Counter<K> extends EHashMap<K, Long> {
    public Counter() {
      super();
    }

    public Counter(int capacity) {
      super(capacity);
    }

    public long add(K key) {
      long result = get(key);
      put(key, result + 1);
      return result + 1;
    }

    public Long get(Object key) {
      if (containsKey(key)) {
        return super.get(key);
      }
      return 0L;
    }

  }

  static class IntIntPair implements Comparable<IntIntPair> {
    public final int first;
    public final int second;

    public IntIntPair(int first, int second) {
      this.first = first;
      this.second = second;
    }

    public static IntIntPair makePair(int first, int second) {
      return new IntIntPair(first, second);
    }

    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || getClass() != o.getClass()) {
        return false;
      }
      IntIntPair pair = (IntIntPair) o;
      return first == pair.first && second == pair.second;
    }

    public int hashCode() {
      int result = first;
      result = 31 * result + second;
      return result;
    }

    public String toString() {
      return "(" + first + ", " + second + ")";
    }

    public int compareTo(IntIntPair o) {
      int value = Integer.compare(first, o.first);
      if (value != 0) {
        return value;
      }
      return Integer.compare(second, o.second);
    }

  }

  static class EHashMap<E, V> extends AbstractMap<E, V> {
    private static final int[] shifts = new int[10];
    private int size;
    private EHashMap.HashEntry<E, V>[] data;
    private int capacity;
    private Set<Entry<E, V>> entrySet;

    static {
      Random random = new Random(System.currentTimeMillis());
      for (int i = 0; i < 10; i++) {
        shifts[i] = 1 + 3 * i + random.nextInt(3);
      }
    }

    public EHashMap() {
      this(4);
    }

    private void setCapacity(int size) {
      capacity = Integer.highestOneBit(4 * size);
      // noinspection unchecked
      data = new EHashMap.HashEntry[capacity];
    }

    public EHashMap(int maxSize) {
      setCapacity(maxSize);
      entrySet = new AbstractSet<Entry<E, V>>() {

        public Iterator<Entry<E, V>> iterator() {
          return new Iterator<Entry<E, V>>() {
            private EHashMap.HashEntry<E, V> last = null;
            private EHashMap.HashEntry<E, V> current = null;
            private EHashMap.HashEntry<E, V> base = null;
            private int lastIndex = -1;
            private int index = -1;


            public boolean hasNext() {
              if (current == null) {
                for (index++; index < capacity; index++) {
                  if (data[index] != null) {
                    base = current = data[index];
                    break;
                  }
                }
              }
              return current != null;
            }


            public Entry<E, V> next() {
              if (!hasNext()) {
                throw new NoSuchElementException();
              }
              last = current;
              lastIndex = index;
              current = current.next;
              if (base.next != last) {
                base = base.next;
              }
              return last;
            }


            public void remove() {
              if (last == null) {
                throw new IllegalStateException();
              }
              size--;
              if (base == last) {
                data[lastIndex] = last.next;
              } else {
                base.next = last.next;
              }
            }
          };
        }


        public int size() {
          return size;
        }
      };
    }

    public EHashMap(Map<E, V> map) {
      this(map.size());
      putAll(map);
    }

    public Set<Entry<E, V>> entrySet() {
      return entrySet;
    }

    public void clear() {
      Arrays.fill(data, null);
      size = 0;
    }

    private int index(Object o) {
      return getHash(o.hashCode()) & (capacity - 1);
    }

    private int getHash(int h) {
      int result = h;
      for (int i : shifts) {
        result ^= h >>> i;
      }
      return result;
    }

    public V remove(Object o) {
      if (o == null) {
        return null;
      }
      int index = index(o);
      EHashMap.HashEntry<E, V> current = data[index];
      EHashMap.HashEntry<E, V> last = null;
      while (current != null) {
        if (current.key.equals(o)) {
          if (last == null) {
            data[index] = current.next;
          } else {
            last.next = current.next;
          }
          size--;
          return current.value;
        }
        last = current;
        current = current.next;
      }
      return null;
    }

    public V put(E e, V value) {
      if (e == null) {
        return null;
      }
      int index = index(e);
      EHashMap.HashEntry<E, V> current = data[index];
      if (current != null) {
        while (true) {
          if (current.key.equals(e)) {
            V oldValue = current.value;
            current.value = value;
            return oldValue;
          }
          if (current.next == null) {
            break;
          }
          current = current.next;
        }
      }
      if (current == null) {
        data[index] = new EHashMap.HashEntry<E, V>(e, value);
      } else {
        current.next = new EHashMap.HashEntry<E, V>(e, value);
      }
      size++;
      if (2 * size > capacity) {
        EHashMap.HashEntry<E, V>[] oldData = data;
        setCapacity(size);
        for (EHashMap.HashEntry<E, V> entry : oldData) {
          while (entry != null) {
            EHashMap.HashEntry<E, V> next = entry.next;
            index = index(entry.key);
            entry.next = data[index];
            data[index] = entry;
            entry = next;
          }
        }
      }
      return null;
    }

    public V get(Object o) {
      if (o == null) {
        return null;
      }
      int index = index(o);
      EHashMap.HashEntry<E, V> current = data[index];
      while (current != null) {
        if (current.key.equals(o)) {
          return current.value;
        }
        current = current.next;
      }
      return null;
    }

    public boolean containsKey(Object o) {
      if (o == null) {
        return false;
      }
      int index = index(o);
      EHashMap.HashEntry<E, V> current = data[index];
      while (current != null) {
        if (current.key.equals(o)) {
          return true;
        }
        current = current.next;
      }
      return false;
    }

    public int size() {
      return size;
    }

    private static class HashEntry<E, V> implements Entry<E, V> {
      private final E key;
      private V value;
      private EHashMap.HashEntry<E, V> next;

      private HashEntry(E key, V value) {
        this.key = key;
        this.value = value;
      }

      public E getKey() {
        return key;
      }

      public V getValue() {
        return value;
      }

      public V setValue(V value) {
        V oldValue = this.value;
        this.value = value;
        return oldValue;
      }

    }

  }
}
