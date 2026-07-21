#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

constexpr bool __debugFlag = false;

class Sushi {
public:
    Sushi () {};
    int64_t x;
    int64_t v;
    int64_t rx;
};

class rotationCalory {
public:
    int64_t calorySum;
    int64_t maxCalorySum;

};

int main(int argc, char **argv) {

    int64_t numberOfSushi;
    int64_t circumference;
    cin >> numberOfSushi >> circumference ;
    
    vector <Sushi> sushis(numberOfSushi);

    for(int64_t i=0; i<numberOfSushi; i++){
        cin >> sushis[i].x >> sushis[i].v;
        sushis[i].rx = circumference - sushis[i].x;
    }

    vector<rotationCalory> rightRotation(numberOfSushi);
    vector<rotationCalory> leftRotation(numberOfSushi);
    
    int64_t maxCalorySum = 0;

    rightRotation[0].calorySum = sushis[0].v - sushis[0].x;
    rightRotation[0].maxCalorySum = rightRotation[0].calorySum;
    for(int64_t i=1; i<numberOfSushi; i++){
        rightRotation[i].calorySum = rightRotation[i-1].calorySum + (sushis[i].v - sushis[i].x + sushis[i-1].x) ;
        rightRotation[i].maxCalorySum = max(rightRotation[i-1].maxCalorySum, rightRotation[i].calorySum);
    }
    maxCalorySum = max(rightRotation[numberOfSushi-1].maxCalorySum, maxCalorySum);

    leftRotation[numberOfSushi-1].calorySum = sushis[numberOfSushi-1].v - sushis[numberOfSushi-1].rx;
    leftRotation[numberOfSushi-1].maxCalorySum = leftRotation[numberOfSushi-1].calorySum;
    for(int64_t i=numberOfSushi-2; i>=0; i--){
        leftRotation[i].calorySum = leftRotation[i+1].calorySum + (sushis[i].v - sushis[i].rx + sushis[i+1].rx) ;
        leftRotation[i].maxCalorySum = max(leftRotation[i+1].maxCalorySum, leftRotation[i].calorySum);
    }
    maxCalorySum = max(maxCalorySum, leftRotation[0].maxCalorySum);
    

    for(int64_t i=0; i<numberOfSushi-1; i++){
        maxCalorySum = max(maxCalorySum, rightRotation[i].calorySum - sushis[i].x + leftRotation[i+1].maxCalorySum);
    }

    for(int64_t i=numberOfSushi-1; i>=1; i--){
        maxCalorySum = max(maxCalorySum, leftRotation[i].calorySum - sushis[i].rx + rightRotation[i-1].maxCalorySum);
    }


    cout << maxCalorySum << endl;


    if (__debugFlag) { 

        cout << numberOfSushi << "," << circumference << endl;
        for(int64_t i=0; i<numberOfSushi; i++){
            cout <<  sushis[i].x << "," << sushis[i].rx  << ","<<  sushis[i].v<< endl;
        }
        cout << "-----------" << endl;
        for(int64_t i=0; i<numberOfSushi; i++){
            cout <<  rightRotation[i].calorySum << ":" << rightRotation[i].maxCalorySum << ",";
            cout <<  leftRotation[i].calorySum << ":" << leftRotation[i].maxCalorySum << endl;
        }
    }
    return 0;

}
