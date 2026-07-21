import std.stdio, std.string, std.conv, std.range;
import std.algorithm, std.array, std.typecons, std.container;
import std.math, std.numeric, std.random, core.bitop;

enum inf = 1_001_001_001;
enum infl = 1_001_001_001_001_001_001L;


struct Deque(T) {
    private {
        int N, head, tail;
        T[] deq;
    }

    this(int n) {
        N = n + 1;
        deq = new T[](N + 1);
    }

    bool empty() {
        return head == tail;
    }

    bool full() {
        return head == ((tail + 1) % N);
    }

    int length() {
        return (tail - head + N) % N;
    }

    T front() {
        assert(!empty);
        return deq[head];
    }

    T back() {
        assert(!empty);
        return deq[(tail - 1 + N) % N];
    }

    void pushFront(T x) {
        assert(!full);
        head = (head - 1 + N) % N;
        deq[head] = x;
    }

    void pushBack(T x) {
        assert(!full);
        deq[tail++] = x;
        tail %= N;
    }

    void popFront() {
        assert(!empty);
        head = (head + 1) % N;
    }

    void popBack() {
        assert(!empty);
        tail = (tail - 1 + N) % N;
    }

    alias insert = pushBack;
    alias removeFront = popFront;
    alias removeBack = popBack;

    T opIndex(size_t index)
    in {
        assert(0 <= index && index < length);
    }
    body {
        return deq[(head + index) % N];
    }

    alias opDollar = length;
}


unittest {
    import std.stdio;

    auto q = Deque!(int)(8);

    q.insert(3);
    q.insert(1);
    q.insert(4);
    q.insert(1);

    assert(q[3] == 1);
    assert(q[0] == 3);

    q.removeFront;
    q.removeFront;

    // q = [4, 1]

    q.insert(8);
    q.pushFront(7);
    q.insert(11);
    q.pushFront(0);

    // q = [0, 7, 4, 1, 8, 11]

    assert(q[0] == 0);
    assert(q[1] == 7);
    assert(q[4] == 8);
    assert(q[$-1] == 11);
}

unittest {
    import std.stdio;

    int n = 5;
    auto deq = Deque!(int)(n);

    deq.pushFront(3);
    deq.pushBack(1);
    deq.pushBack(4);
    deq.pushFront(5);

    assert(deq.front == 5);
    assert(deq.back == 4);
    assert(deq.length == 4);

    deq.pushFront(0);

    assert(deq.full);
    assert(deq.front == 0);
    assert(deq.length == 5);

    deq.popFront();
    deq.popFront();
    deq.popBack();

    assert(deq.front == 3);
    assert(deq.back == 1);
    assert(deq.length == 2);

    deq.popBack();
    deq.popFront();

    assert(deq.empty);
    assert(deq.length == 0);
}



void main() {
    string s;
    scan(s);

    auto deq = Deque!(char)(4 * 10^^5);
    foreach (ch ; s) {
        deq.pushBack(ch);
    }

    int Q;
    scan(Q);
    bool rev;

    foreach (_ ; 0 .. Q) {
        auto ln = readln.split;
        if (ln.front == "1") {
            rev ^= 1;
        }
        else {
            auto f = ln[1].to!int;
            auto c = ln[2].to!char;
            f--;
            if ((f ^ rev) == 0) {
                deq.pushFront(c);
            }
            else {
                deq.pushBack(c);
            }
        }
    }

    string ans;
    if (!rev) {
        while (!deq.empty) {
            ans ~= deq.front;
            deq.removeFront();
        }
    }
    else {
        while (!deq.empty) {
            ans ~= deq.back;
            deq.removeBack();
        }
    }

    writeln(ans);
}




void scan(T...)(ref T args) {
    auto line = readln.split;
    foreach (ref arg; args) {
        arg = line.front.to!(typeof(arg));
        line.popFront;
    }
    assert(line.empty);
}

void fillAll(R, T)(ref R arr, T value) {
    static if (is(typeof(arr[] = value))) {
        arr[] = value;
    }
    else {
        foreach (ref e; arr) {
            fillAll(e, value);
        }
    }
}

bool chmin(T, U...)(ref T x, U args) {
    bool isChanged;
    foreach (arg; args) if (x > arg) {
        x = arg;
        isChanged = true;
    }
    return isChanged;
}

bool chmax(T, U...)(ref T x, U args) {
    bool isChanged;
    foreach (arg; args) if (x < arg) {
        x = arg;
        isChanged = true;
    }
    return isChanged;
}
