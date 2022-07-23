##Find duplicate element.
# n element array has elements from 0-n-2. find duplicate.
l=[0,1,2,3,4,5,5]
n=len(l)
sum_n_2= (n-2)*(n-1)/2
sum_l=sum(l)
print(sum_l-sum_n_2)

"""def func(l):
    d={}
    for i in l:
        if i not in d.keys():
            d[i]=d.get(i,0)+1
        else:
            return i
    return -1
print(func(l))"""
