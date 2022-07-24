#inversion count
l=[5,4,2,3,1]
"""count=0
for i in range(len(l)):
    for j in range(i,len(l)):
        if l[i]>l[j]:
            count+=1
print(count)"""
def merge(l,left,mid,right):
    i,j,k=left,mid+1,0
    temp=[-1 for i in range(right-left+1)]
    count=0
    while i<=mid and j<=right:
        if l[i]<=l[j]:
            temp[k]=l[i]
            k+=1
            i+=1
        else:
            temp[k]=l[j]
            k+=1
            j+=1
            count+=(mid-i+1)
    while(i<=mid):
        temp[k]=l[i]
        i+=1
        k+=1
    while(j<=right):
        temp[k]=l[j]
        j+=1
        k+=1
    l=temp
    return count
def merge_sort(l,left,right):
    count=0
    if left<right:
        mid=int((left+right)/2)
        lcount=merge_sort(l,left,mid)
        rcount=merge_sort(l,mid+1,right)
        mycount=merge(l,left,mid,right)
        return lcount+rcount+mycount
    return count
def solve(l):
    ans=merge_sort(l,0,len(l)-1)
    return ans
print(solve(l))
    