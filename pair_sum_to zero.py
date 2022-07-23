##pair su, to 0
l=[2, 1 ,-2, 2 ,3]
count=0
d={}
for i in l:
    if -i in d.keys():
        count+=1
    d[i]=d.get(i,0)+1
print(count)


"""for i in l:
    if i in d.keys():
        if -i in d.keys():
            count+=1
            d[-i]-=1
            if d[-i]==0:
                del d[-i]

            d[i]-=1
            if d[i]==0: del d[i]

print(count)"""