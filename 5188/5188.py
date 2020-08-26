def isNotOut(x, y):
    return 0<=x<N and 0<=y<N

def DFS(x, y):
    global sub_result, result

    if result < sub_result:
        return
    
    if x == N-1 and y == N-1:
        result = sub_result
        return

    for dir in range(2):
        New_X = x + dx[dir]
        New_Y = y + dy[dir]
        
        if isNotOut(New_X, New_Y) and (New_X, New_Y) not in visited:
            visited.append((New_X, New_Y))
            sub_result += Data[New_X][New_Y]
            DFS(New_X, New_Y)
            visited.remove((New_X, New_Y))
            sub_result -= Data[New_X][New_Y]

T = int(input())
for t in range(1, T+1):
    N = int(input())
    Data = [list(map(int, input().split())) for _ in range(N)]

    visited = []

    dx = [1, 0] # 하
    dy = [0, 1] # 우

    sub_result, result = Data[0][0], 6974892
    DFS(0, 0)
    print("#%d %d"%(t, result))