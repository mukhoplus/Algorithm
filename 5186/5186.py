T = int(input())
for i in range(T):
    N = float(input())
    cnt = 0
    temp = N
    answer = ""
    while(1):
        temp = temp * 2
        answer += str(int(temp))
        cnt = cnt + 1

        temp = temp - int(temp)
        if temp == 0.0:
            break
        if cnt > 12:
            answer = "overflow"
            break

    print(f"#{i+1} {answer}")