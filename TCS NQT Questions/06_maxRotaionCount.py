from posixpath import split


n = int(input())
a = list(map(int,input().split(" ")))
b = []

for i in range(1, n+1):
    b.append(i)

ans = 0
k = 0

d =[0]*n
while d!=b:
    if k==0:
        d = b
        k+=1
    c = [0]*n
    for i in range(n):
        c[a[i] - 1] = b[i]
    b = c
    ans+=1
print(ans)