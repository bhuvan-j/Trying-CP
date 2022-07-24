#codechef_variation
def variationPairs(l,n,k):
    l.sort()
    i,j=0,1 
    count=0
    while j<n:
        if l[j]-l[i]>=k:
            count+=(n-j)
            i+=1
        else:
            j+=1
    return count
        
n,k=map(int,input().strip().split())
l=list(map(int,input().split()))
print(variationPairs(l,n,k))
print()

"""N, K = map(int,input().split())
A = list(map(int,input().split()))
A.sort()
ans = 0
i,j = 0,1

while(j<N):
    if A[j] - A[i] >= K :
        i += 1
        ans += N - j
    else :
        j += 1"""
"""print(ans)"""