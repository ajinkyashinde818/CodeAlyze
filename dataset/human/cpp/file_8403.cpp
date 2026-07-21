//
// Created by tattsun on 2017/02/11.
//
#include <iostream>
#include <vector>

using namespace std;

enum Color : int {
    None,
    Black,
    White,
};


Color char_to_color(char i) {
    if(i == '#') return Color::Black;
    return Color::White;
}

int n, m;
Color a[50][50], b[50][50];

bool _solve(int y, int x) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            Color p = a[i+y][j+x];
            Color q = b[i][j];
            if(p != q)
                return false;
        }
    }
    return true;
}

bool solve() {
    for(int i=0; i<n-m+1; i++) {
        for(int j=0; j<n-m+1; j++) {
            if(_solve(i,j)) return true;
        }
    }
    return false;
}

int main() {
    for(int i=0; i<50; i++) {
        for(int j=0; j<50; j++) {
            a[i][j] = Color::None;
            b[i][j] = Color::None;
        }
    }

    cin >> n >> m;

    string cs;
    for(int i=0; i<n; i++) {
        cin >> cs;
        for(int j=0; j<n; j++) {
            a[i][j] = char_to_color(cs[j]);
        }
    }
    for(int i=0; i<m; i++) {
        cin >> cs;
        for(int j=0; j<m; j++) {
            b[i][j] = char_to_color(cs[j]);
        }
    }

    if(solve()) cout << "Yes" << endl;
    else cout << "No" << endl;
}
