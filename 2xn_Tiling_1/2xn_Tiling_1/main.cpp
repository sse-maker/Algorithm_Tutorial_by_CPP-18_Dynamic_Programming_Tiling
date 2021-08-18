//
//  main.cpp
//  1_2xn_Tiling
//
//  Created by 세광 on 2021/08/18.
//

// 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램

#include <iostream>

using namespace std;

long long int d[1001];

long long int DP(int x) {
    if (x == 1) return 1;
    if (x == 2) return 2;
    if (d[x] != 0) return d[x];
    return d[x] = DP(x - 1) + DP(x - 2);
}

int main() {
    int x;
    cin >> x;
    cout << DP(x) << endl;
}

