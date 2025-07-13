#include <iostream>
#include <vector>
using namespace std;

class LinearBasis {
private:
    vector<long long> basis; // 存储线性基

public:
    LinearBasis() {
        basis.resize(50, 0); // 因为数字小于2^50，所以需要50位
    }

    // 插入一个数到线性基中
    void insert(long long x) {
        for (int i = 49; i >= 0; --i) {
            if ((x >> i) & 1) {
                if (basis[i] == 0) {
                    basis[i] = x;
                    return;
                }
                x ^= basis[i];
            }
        }
    }

    // 求最大异或和
    long long getMaxXor() {
        long long res = 0;
        for (int i = 49; i >= 0; --i) {
            if ((res ^ basis[i]) > res) {
                res ^= basis[i];
            }
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    LinearBasis lb;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        lb.insert(x);
    }
    cout << lb.getMaxXor() << endl;
    return 0;
}