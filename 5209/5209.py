# p = 제품, y = 공장
def DFS(p, sum):
    global result

    if p == N:
        if result > sum:
            result = sum
        return
    if result < sum:
        return
    
    for y in range(N):
        if not visited[y]:
            visited[y] = True
            DFS(p+1, sum+Data[p][y])
            visited[y] = False
    
T = int(input())
for tc in range(1, T+1):
    N = int(input())
    Data = [list(map(int, input().split())) for _ in range(N)]
    visited = [0] * N
    result = 9999999

    DFS(0, 0)
    print("#%d %d"%(tc, result))