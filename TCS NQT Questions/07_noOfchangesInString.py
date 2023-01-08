a = input()
b = input()
n = len(a)

ans = 0
for i in range(n):
    if a[i] < b[i]:
        ans = -1

z1 = ord('z')
a1 = ord('a')

if ans == 0:
    for i in range(z1, a1 -1, -1):
        c = 0
        for j in range(n):
            if b[j] == chr(i) and a[j] != chr(i):
                c+=1
        if(c > 0):
            if chr(i) in a:
                ans+=1
            else:
                ans-=1
                break
print(ans)