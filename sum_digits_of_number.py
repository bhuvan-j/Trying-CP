##Sum me up
num=int(input())

l=[]
while num>0:
    rem=num%10
    num=num//10
    l.append(int(rem))
print(sum(l))