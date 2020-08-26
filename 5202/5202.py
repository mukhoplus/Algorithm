T = int(input())

for tc in range(1, T+1):
    N = int(input()) # 신청서
    Data = []
    for i in range(N): # 입력
        s, e = map(int, input().split()) # s = 시작 시간, e = 종료 시간
        Data.append([s, e])
    
    # 종료 시간 기준으로 오름차순 정렬 *****************
    for i in range(N):
        for j in range(i, N):
            if(Data[i][1] > Data[j][1]):
                Data[i], Data[j] = Data[j], Data[i]
    
    result = []
    visited = [0] * N

    # 첫 운송
    result.append(Data[0])
    visited[0] = True

    while True:
        for i in range(N):
            if result[-1][-1] > Data[i][0]: # 현재 마지막 운송의 종료시간보다, 신청서에 있는 시작시간이 작으면 visited를 true로 해서 계산하지 않음(삭제)
                visited[i] = True

        if not 0 in visited: # 만약 모두가 쓰레기 값이면 삭제
            break

        index = 0 # i 저장용
        value = 99999999 # 종료시간 비교용
        for i in range(N):
            # 아직 검토되지 않은 신청목록이고, 해당 목록의 시작 시간이 현재 목록의 종료 시간 이상이며, 현재 목록의 종료 시간이 비교시간(시작시간)보다 작은가 **********************
            if visited[i] == 0 and result[-1][-1] <= Data[i][0] and Data[i][1] < value:
                index = i # 인덱스 저장
                value = Data[i][0] # 저장한 값의 시작시간 저장
        result.append(Data[index])
    print("#%d %d"%(tc, len(result)))