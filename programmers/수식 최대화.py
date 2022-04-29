from itertools import permutations
'''
combinations: 조합(중복 x), combinations(lst, len(lst))
permutations: 순열(중복 x), permutations(lst, len(lst))
product: 순열(중복 x), product(lst, repeat=1)
'''

def solution(expression):
    answer = -1
    custom = [] # 짝수: 숫자, 홀수: 연산자
    exps = [] # 연산자 + - *
    temp = ''

    for x in expression:
        if x.isdigit():
            temp += x
        else:
            custom.append(int(temp))
            custom.append(x)
            if x not in exps:
                exps.append(x)
            temp = ''
    custom.append(int(temp)) # 마지막 숫자

    for combi in permutations(exps, len(exps)):
        combi = list(combi)
        temp = custom[:]
        for e in combi:
            i = -1
            t = len(temp)
            while t > 1:
                try:
                    i = temp.index(e)
                except:
                    break

                if e == '+':
                    temp[i-1] += temp[i+1]
                elif e == '-':
                    temp[i-1] -= temp[i+1]
                else:
                    temp[i-1] *= temp[i+1]

                # 연산에 사용한 연산자와 두번째 피연산자를 제거함
                del temp[i+1]
                del temp[i]
                t -= 2

        answer = abs(temp[0]) if answer < abs(temp[0]) else answer

    return answer

expression = "100-200*300-500+20"
answer = solution(expression)
print(answer)