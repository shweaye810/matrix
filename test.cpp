#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    q.push(1);
    cout << q.front();
    cout << q.back();
    q[0] = 2;
}
