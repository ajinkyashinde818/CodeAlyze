#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <set>
using namespace std;

//関数getinputdata宣言
vector<vector<string>> getinputdata();
vector<vector<int>> getinputdata2();
vector<vector<double>> getinputdata3();

void diverta2019_b(vector<vector<string>> v) {

    int r = atoi(v[0][0].c_str());
    int g = atoi(v[0][1].c_str());
    int b = atoi(v[0][2].c_str());
    int n = atoi(v[0][3].c_str());
    int cnt = 0;

    for (int i = 0; i <= n; i++) {

        for (int j = 0; j <= n; j++) {

            //            for (int k = 0; k <= n; k++) {



            int nokori = n - (i * r + j * g);
            
            if(nokori<0){
                break;
            }

//            cout << i << " " << j << " " << nokori<< " " << (nokori%b) <<endl;
            if (nokori % b == 0) {
                cnt += 1;
            }

        }
    }


    cout << cnt << endl;

}

int main() {

    vector<vector < string>> vec_arr_result;
    //    vector<vector<int>> vec_arr_result;
    vec_arr_result = getinputdata();

    diverta2019_b(vec_arr_result);

    return 0;
}

//関数getinputdata実装

vector<vector<double>> getinputdata3() {

    string str;
    string ret;
    stringstream ss;
    vector<string> v1;
    vector<vector<double>> vec_arr;

    //標準入力から入力がある間ループ処理でvector配列にデータ格納
    while (getline(cin, str)) {

        v1.push_back(str);

    }

    //stringstreamを利用してvector配列v1をスペースで分解処理
    for (string s : v1) {

        vector<double> array_data;
        ss << s;

        while (!ss.eof()) {

            ss >> ret;

            array_data.push_back(atof(ret.c_str()));
        }

        //vector配列に追加
        vec_arr.push_back(array_data);

        //バッファクリア
        ss.str("");
        //ストリームクリア
        ss.clear(stringstream::goodbit);

    }

    return vec_arr;
}

//関数getinputdata実装

vector<vector<int>> getinputdata2() {

    string str;
    string ret;
    stringstream ss;
    vector<string> v1;
    vector<vector<int>> vec_arr;

    //標準入力から入力がある間ループ処理でvector配列にデータ格納
    while (getline(cin, str)) {

        v1.push_back(str);

    }

    //stringstreamを利用してvector配列v1をスペースで分解処理
    for (string s : v1) {

        vector<int> array_data;
        ss << s;

        while (!ss.eof()) {

            ss >> ret;

            array_data.push_back(atoi(ret.c_str()));
        }

        //vector配列に追加
        vec_arr.push_back(array_data);

        //バッファクリア
        ss.str("");
        //ストリームクリア
        ss.clear(stringstream::goodbit);

    }

    return vec_arr;


}

//関数getinputdata実装

vector<vector < string >> getinputdata() {

    string str;
    string ret;
    stringstream ss;
    vector<string> v1;
    vector<vector < string>> vec_arr;

    //標準入力から入力がある間ループ処理でvector配列にデータ格納
    while (getline(cin, str)) {

        v1.push_back(str);

    }

    //stringstreamを利用してvector配列v1をスペースで分解処理
    for (string s : v1) {

        vector<string> array_data;
        ss << s;

        while (!ss.eof()) {

            ss >> ret;

            array_data.push_back(ret);
        }

        //vector配列に追加
        vec_arr.push_back(array_data);

        //バッファクリア
        ss.str("");
        //ストリームクリア
        ss.clear(stringstream::goodbit);

    }

    return vec_arr;

}
