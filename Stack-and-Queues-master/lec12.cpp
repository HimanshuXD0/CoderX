// The Celebrity Probelm
// https://youtu.be/CiiXBvrX-5A?si=OTJPfRtvgNtTKRS8
// Revision Status : 0

#include <bits\stdc++.h>
using namespace std;

int celebrity(int M[100][100], int n) {
    stack<int> s;
    
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    while (s.size() > 1) {
        int person1 = s.top();
        s.pop();
        int person2 = s.top();
        s.pop();

        // person1 doesn't know person2
        if (M[person1][person2] == 0) {
            s.push(person1);
        }
        // person2 doesn't know person1
        else if (M[person2][person1] == 0) {
            s.push(person2);
        }
    }

    // if both people know each other
    if (s.empty()) {
        return -1;
    }

    int eligibleCelebrity = s.top();

    // Check if eligibleCelebrity knows anyone
    for (int j = 0; j < n; j++) {
        if (M[eligibleCelebrity][j] == 1) {
            return -1;
        }
    }

    // Check if anyone knows eligibleCelebrity
    for (int i = 0; i < n; i++) {
        if (i == eligibleCelebrity) {
            continue;
        }

        if (M[i][eligibleCelebrity] == 0) {
            return -1;
        }
    }

    return eligibleCelebrity;
}

int main() {
    int M[100][100] = {{0, 0, 1, 0},
                       {0, 0, 1, 0},
                       {0, 0, 0, 0},
                       {0, 0, 1, 0}};

    int n = 4;

    int result = celebrity(M, n);

    if (result != -1) {
        cout << "The celebrity is person " << result << endl;
    } else {
        cout << "No celebrity found" << endl;
    }

    return 0;
}
