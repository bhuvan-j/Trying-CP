t=int(input())
def lowerbound(intervals,ass):
    s=0
    e=len(intervals)-1
    lower_bound=-1
    while s<=e:
        mid=(s+e)//2
        #print("s,mid,e is",s,mid,e)
        if intervals[mid][0]<=ass:
            #print(ass," >= ",intervals[mid][0])
            s=mid+1
        else:
            #print(ass," < ",intervals[mid][0])
            lower_bound=mid
            #print("lower bound is", lower_bound)
            e=mid-1
    #print("lower_bound is:",lower_bound)
    return lower_bound if lower_bound!=-1 else len(intervals)
for tc in range(t):
    pers=[]
    intervals=[]
    n,m=map(int,input().split(" "))
    for j in range(n):
        l,r=map(int,input().split(" "))
        intervals.append([l,r])
    intervals.sort()
    #print(intervals)
    for j in range(m):
        pers=int(input())
        pos=lowerbound(intervals,pers)
        #print("pos:",pos)
        if pos==0:
            ans=intervals[0][0]-pers
            print(ans)
        else:
            ans=-1
            if intervals[pos-1][1]>pers:    ans=0
            elif pos<len(intervals):    ans=intervals[pos][0]-pers
            print(ans)
                