#include <vector>
#include <numeric> // 用于 std::iota

class UnionFind {
private:
    // parent[i] 表示元素 i 的父节点
    std::vector<int> parent;
    // size[i] 表示以 i 为根的集合的大小（只在 i 是根节点时有意义）
    std::vector<int> size;
    // 记录连通分量的数量
    int count;

public:
    // 构造函数：初始化 n 个元素的并查集
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        // std::iota 是一个方便的函数，用 0, 1, 2, ... 来填充容器
        std::iota(parent.begin(), parent.end(), 0); 
        // 每个集合初始大小都为 1
        size.assign(n, 1);
    }

    // 查找元素 x 的根节点（带路径压缩）
    int find(int x) {
        // 如果 x 的父节点不是它自己，说明 x 不是根节点
        if (parent[x] != x) {
            // 递归查找根节点，并直接将 x 的父节点指向根节点（路径压缩）
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 合并元素 x 和元素 y 所在的集合（按大小合并）
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        // 如果根节点不同，说明它们不在同一个集合中，可以合并
        if (rootX != rootY) {
            // 按大小合并：将小集合合并到大集合中
            if (size[rootX] < size[rootY]) {
                std::swap(rootX, rootY); // 确保 rootX 是较大集合的根
            }
            // 将小集合的根(rootY)指向大集合的根(rootX)
            parent[rootY] = rootX;
            // 更新大集合的大小
            size[rootX] += size[rootY];
            // 连通分量数量减一
            count--;
        }
    }

    // 检查两个元素是否在同一个集合中
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    // 返回当前连通分量的数量
    int getCount() const {
        return count;
    }
    
    // 返回元素 x 所在集合的大小
    int getSize(int x) {
        return size[find(x)];
    }
};

int main (void) {

    ios :: sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

    return 0;
}