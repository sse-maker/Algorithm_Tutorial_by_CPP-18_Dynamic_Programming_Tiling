//
//  main.cpp
//  Fill_Tiling_1
//
//  Created by 세광 on 2021/08/18.
//

// 3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구하는 프로그램

#include <iostream>

using namespace std;

long long int d[1001];

long long int DP(int x) {
    if (x == 0) return 1;
    if (x == 1) return 0;
    if (x == 2) return 3;
    if (d[x] != 0) return d[x];
    long long int result = 3 * DP(x - 2);
    for (int i = 3; i <= x; i++) {
        if (i % 2 == 0) result += 2 * DP(x - i);
    }
    return d[x] = result;
}

int main() {
    int x;
    cin >> x;
    cout << DP(x) << endl;
}
