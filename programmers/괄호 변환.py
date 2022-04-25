'''
코딩테스트 연습 >> 2020 KAKAO BLIND RECRUITMENT >> 괄호 변환
https://programmers.co.kr/learn/courses/30/lessons/60058
'''
# 균형잡힌 괄호 문자열: '(' 와 ')' 로만 이루어진 문자열이 있을 경우, '(' 의 개수와 ')' 의 개수가 같은 문자열
def check_bal(w):
    num_open = 0
    num_close = 0
    
    for s in w:
        if s == '(':
            num_open += 1
        else:
            num_close += 1
            
    if num_open == num_close:
        return True
    else:
        return False

# 올바른 괄호 문자열: 균형잡힌 괄호 문자열에 '('와 ')'의 괄호의 짝도 모두 맞을 경우
def check_cor(w):
    temp = []
    
    for i in range(len(w)):
        if len(temp) == 0 or (temp[-1] == '(' and w[i] == '('):
            temp.append(w[i])
        elif temp[-1] == '(' and w[i] == ')':
            temp.pop()
        else:
            temp = [0]
            break

    if len(temp) == 0:
        return True
    else:
        return False

# '(' 와 ')' 로만 이루어진 문자열 w가 "균형잡힌 괄호 문자열" 이라면 "올바른 괄호 문자열"로 변환하는 함수
# 이때, 전제에 의해 w는 무조건 균형잡힌 괄호 문자열이다.
def recur(w):
    # 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
    if len(w) == 0:
        return w
    
    # 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다.
    # 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
    for i in range(1, len(w), 2):
        u = w[:i+1]
        v = ''
        if check_bal(u):
            if i+1 < len(w):
                v = w[i+1:]
        else:
            continue

        output = ''
        # 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
        #   3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
        if check_cor(u):
            output = u + recur(v)
        else:
            # 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
            if not check_cor(u):
                #   4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
                #   4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
                #   4-3. ')'를 다시 붙입니다.
                output = '(' + recur(v) + ')'
                #   4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
                for i in range(1, len(u)-1):
                    if u[i] == '(':
                        output += ')'
                    else:
                        output += '('

        #   4-5. 생성된 문자열을 반환합니다.
        return output

def solution(p):
    answer = recur(p)
    
    return answer
