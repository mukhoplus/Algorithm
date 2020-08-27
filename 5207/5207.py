def BinarySearch(lst, l, r, key):
    global cnt, where
    if l > r:
        return

    m = int((l+r)/2)

    if key == lst[m]:
        cnt += 1
    elif key < lst[m]:
        if where == -1:
            return
        where = -1
        BinarySearch(lst, l, m-1, key)
    elif lst[m] < key:
        if where == 1:
            return
        where = 1
        BinarySearch(lst, m+1, r, key)

T = int(input())
for tc in range(1, T+1):
    N, M = input().split() # N = A 원소의 개수, M = B 원소의 개수 
    A = sorted(list(map(int, input().split()))) # 검색할 리스트
    B = list(map(int, input().split())) # 여기에 있는 숫자를 A에서 찾을거임

    cnt = 0
    where = 0
    for k in(B):
        BinarySearch(A, 0, len(A)-1, k)

    print("#%d %d"%(tc, cnt))