from collections import deque #덱이 가장 빠른 결과를 보여준다고 함

def calc(num, calc):
    if calc == 0:
        return num+1
    elif calc == 1:
        return num-1
    elif calc == 2:
        return num*2
    else:
        return num-10

def BFS(N, M):
    global tc
    Q = deque()
    Q.append((N,0))
    num_lst[N] = tc

    while Q:
        num, cnt = Q.popleft()
        for i in range(4):
            next_num = calc(num, i)
            if next_num == M: # 찾으려는 숫자
                return cnt+1
            elif 1<=next_num<=1000000 and num_lst[next_num] != tc:#조건에 맞는가
                Q.append((next_num, cnt+1))
                num_lst[next_num] = tc # 궤적

T = int(input())
num_lst = [0] * 1000001 #탐색 궤적 리스트(시간 단축용)
for tc in range(1, T+1):
    N, M = map(int, input().split())
    print("#{} {}".format(tc, BFS(N, M)))