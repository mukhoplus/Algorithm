T = int(input())
for tc in range(1,T+1):
    N, M = map(int, input().split()) # N = 컨테이너 수, M = 트럭 수
    weight = list(map(int, input().split())) # w_i 화물의 무게
    truck = list(map(int, input().split())) # t_i 트럭의 적재용량

    answer = 0 # 한번에 옮길 수 있는 총 무게
    for i in range(M): # 트럭 수 만큼 비교
        result = 0

        for unit_weight in weight: # 화물을 하나씩 꺼냄
            if truck[i] >= unit_weight and unit_weight >= result: # 화물 중 트럭의 적재용량을 가장 꽉 채울 수 있는 것을 선택
                result = unit_weight
        if result != 0:
            weight.remove(result) # 실은 것은 삭제
        answer += result
    
    print("#%d %d"%(tc, answer))