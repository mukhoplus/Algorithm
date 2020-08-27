def quick_sort(A, l, r):
    if l < r:
        p = partition(A, l, r)
        quick_sort(A, l, p-1)
        quick_sort(A, p+1, r)

def partition(A, l, r):
    pivot = (l+r)//2 # mid value
    while l < r:
        while A[l] < A[pivot] and l < r: #왼쪽에서부터 pivot보다 큰 값을 찾을 때 까지 이동. 단, l<r을 만족해야 함.
            l += 1
        while A[r] >= A[pivot] and l < r: #오른쪽에서부터 pivot보다 작은 값을 찾을 때 까지 이동. 단, l<r을 만족해야 함.
            r -= 1
        if l < r:
            if l == pivot: # 최악인 경우, pivot값 교체
                pivot = r
            A[l], A[r] = A[r], A[l]
    A[pivot], A[r] = A[r], A[pivot]
    return r

T = int(input())
for tc in range(1, T+1):
    N = int(input())
    A = list(map(int, input().split()))
    quick_sort(A, 0, N-1)
    print("#%d %d"%(tc, A[N//2]))