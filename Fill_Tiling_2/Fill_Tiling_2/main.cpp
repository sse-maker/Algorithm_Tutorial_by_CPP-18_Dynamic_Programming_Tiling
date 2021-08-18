//
//  main.cpp
//  Fill_Tiling_2
//
//  Created by 세광 on 2021/08/18.
//

// 2×N 크기의 벽을 2×1, 1×2, 1×1 크기의 타일로 채우는 경우의 수를 구하는 프로그램
// 2차원 다이나믹 프로그래밍 기법 사용 - 2씩 더해지는 부분을 처리하기 위해 배열에 별도의 행을 만들어 처리 (시간 복잡도: O(N))

#include <iostream>

using namespace std;

long long int d[1000001][2];

long long int DP(int x) {
    d[0][0] = 0;
    d[1][0] = 2;
    d[2][0] = 7;
    d[2][1] = 1;
    for (int i = 3; i <= x; i++) {
        d[i][1] = d[i - 1][1] + d[i - 3][0];
        d[i][0] = 3 * d[i - 2][0] + 2 * d[i - 1][0] + 2 * d[i][1];
    }
    return d[x][0];
}

int main() {
    int x;
    cin >> x;
    cout << DP(x) << endl;
}
