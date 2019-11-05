#include <cstdio>
#include <vector>

struct LINKLIST {
    int addr;//地址
    int data;//数据
    int next;//下一个节点地址
};

const int MAXN = 1e5;
LINKLIST data[MAXN];

int main() {
    int addr_s;//开始地址
    int n, k, i;
    LINKLIST node;
    std::vector<LINKLIST> vin;//输入
    std::vector<LINKLIST> vout;//输出

    scanf("%d %d %d", &addr_s, &n, &k);
    for (i=0; i<n; i++) {
        scanf("%d %d %d", &node.addr, &node.data, &node.next);
        data[node.addr] = node;
    }

    //建立链表
    i = addr_s;
    while (i!=-1) {
        vin.push_back(data[i]);
        i = data[i].next;
    }

#if 1
    int n_new = vin.size();//排序后的链的大小，不一定等于N，因为可能存在废点不在链上
    int right = k - 1;
    while (right<n_new) {
        for (i=right; i>right-k; i--) {
            vout.push_back(vin[i]);
        }
        right += k;
    }
    for (i=right-k+1; i<n_new; i++) {
        vout.push_back(vin[i]);
    }
    for (i=0; i<n_new-1; i++) {
        printf("%05d %d %05d\n", vout[i].addr, vout[i].data, vout[i+1].addr);
    }
    //最后一个节点
    printf("%05d %d -1\n", vout[i].addr, vout[i].data);
#else
    //反转
    int r = myl.size()/k;
    for(i=1; i<=r; i++) {
        std::reverse(myl.begin()+(i-1)*k , myl.begin()+i*k);
    }

    //输出
	std::vector<LINKLIST>::iterator it;
	for(it=myl.begin();it!=myl.end()-1;it++) {
	   printf("%05d %d %05d\n",it->addr,it->data,(it+1)->addr);
    }
	printf("%05d %d %d\n",it->addr,it->data,-1);  
#endif

    return 0;
}