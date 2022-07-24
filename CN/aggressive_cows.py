#Aggressive Cows
l=[1,8,9,4,2] # position of stalls
#minimum d can be 0 and max d can be 9-1=8
# so 0<=d<=8
n=len(l)
noofcows=3

def canarrange(cows,l,n,dist):
    count=1
    last_pos=l[0]
    for i in range(1,n):
        if l[i]-last_pos>=dist:
            last_pos=l[i]
            count+=1
        if count==cows:
            return True
    return False

def aggresive_cows(l,noofcows,n):
    l.sort()
    ans=-1
    d=[i for i in range(1,9)]
    s,e=0,len(d)-1
    while(s<=e):
        mid=int((s+e)/2)
        if canarrange(noofcows,l,n,d[mid]):
            ans=d[mid]
            s=mid+1
        else:
            e=mid-1
    return ans

print(aggresive_cows(l,noofcows,n))