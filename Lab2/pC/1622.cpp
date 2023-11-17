#include "1622.h"
#include <vector>
#include <iostream>
struct Range
{
    int idx_l, idx_r;
    int cut;
};

Number two_increasing_arrays(int n, int k, std::vector<Number> a, std::vector<Number> b) {
    
    Range an, bn;
    int cut, cutl, cutr;
    an.idx_l = 1;
    bn.idx_l = 1;
    if (k%2==1)
    {
        cut = (k+1)/2;
        an.cut = (k+1)/2;
        bn.cut = (k-1)/2;
    }
    else
    {
        cut = k / 2;
        an.cut = cut;
        bn.cut = cut;
    }
    //an.idx_r = n;
    //an.cut = (an.idx_l + an.idx_r) / 2;
    //bn.idx_r = n;
     //bn.cut = (bn.idx_l + bn.idx_r) / 2;
    while(an.idx_l + bn.idx_l <= k) 
    {

        //std::cout << "a(l,r): " << an.idx_l << " " << an.idx_r << "\n";
        //std::cout << "b(l,r): " << bn.idx_l << " " << bn.idx_r << "\n";
        int add;
        if(an.idx_l > n)
            return b[k - n - 1];
        else if(bn.idx_l > n)
            return a[k - n - 1];
        cut /= 2;
        if(a[an.cut - 1] > b[bn.cut - 1])
        {
            bn.idx_l = bn.cut + 1;
            add = (k-an.idx_l-bn.idx_l+2) / 2;
            while(bn.cut + add > n)
            {
                add /= 2;
            }
            an.cut -= add;
            bn.cut += add;
        }
        else
        {
            an.idx_l = an.cut + 1;
            add = (k-an.idx_l-bn.idx_l+2) / 2;
            while(an.cut + add > n)
            {
                add /= 2;
            }
            an.cut += add;
            bn.cut -= add;
        }
    }
    if(an.idx_l > n)
        return b[k - n - 1];
    else if(bn.idx_l > n)
        return a[k - n - 1];
    else if(a[an.idx_l - 1] > b[bn.idx_l - 1])
        return b[bn.idx_l - 1];
    else
        return a[an.idx_l - 1];
}
