#include <iostream>
// https://lyzqm.blogspot.com/2017/11/2104-12846.html
typedef long long ll;
inline ll min(ll a ,ll b) { return a> b ? b : a;}
inline ll max(ll a, ll b) { return a> b ? a : b;}

int N;
ll arr[100001];
ll sum[100001];

ll solve(int l ,int r){
    if(l==r) {
        return arr[l]*arr[l];
    }
    int mid=(l+r)>>1;
    ll ret=max(solve(l,mid),solve(mid+1,r));
    int left= mid;
    int right=mid+1;
    ll Min=min(arr[left],arr[right]);
    ret = max(ret,(arr[left]+arr[right]) *Min);

    while(l<left||right<r){
        if(l==left||(right<r&& arr[right+1]>arr[left-1] ) ) right++,Min=min(Min,arr[right]);
        else left--, Min=min(Min,arr[left]);
        ret=max(ret,sum[right]-(left==0? 0 : sum[left-1])*Min);
    }
    return ret;
}