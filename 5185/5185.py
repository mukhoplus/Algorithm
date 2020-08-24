T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    # ///////////////////////////////////////////////////////////////////////////////////
    N = int(input())
    hexStr = input()

    bnsStr = ""
    for i in range(N):
        if hexStr[i] == '0':
            bnsStr += '0000'
        elif hexStr[i] == '1':
            bnsStr += '0001'
        elif hexStr[i] == '2':
            bnsStr += '0010'
        elif hexStr[i] == '3':
            bnsStr += '0011'
        elif hexStr[i] == '4':
            bnsStr += '0100'
        elif hexStr[i] == '5':
            bnsStr += '0101'
        elif hexStr[i] == '6':
            bnsStr += '0110'
        elif hexStr[i] == '7':
            bnsStr += '0111'
        elif hexStr[i] == '8':
            bnsStr += '1000'
        elif hexStr[i] == '9':
            bnsStr += '1001'
        elif hexStr[i] == 'A':
            bnsStr += '1010'
        elif hexStr[i] == 'B':
            bnsStr += '1011'
        elif hexStr[i] == 'C':
            bnsStr += '1100'
        elif hexStr[i] == 'D':
            bnsStr += '1101'
        elif hexStr[i] == 'E':
            bnsStr += '1110'
        else:
            bnsStr += '1111'
    print("#{} {}".format(test_case + 1, bnsStr))
'''
hex_to_dec = {'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F':15}

for test_case in range(int(input())):
    N, hexStr = input().split()
    bnsStr = ''

    for i in hexStr:
        if '0' <= i <= '9':
            temp = int(i)
        else:
            temp = hex_to_dec[i]

        #16진수는 2진수 4글자이므로 8을 사용
        num = 8
        for j in range(4):
            if temp & num:
                bnsStr += '1'
            else:
                bnsStr += '0'
            num >>= 1 # 비트연산하는 값을 반 줄이기
            
    print("#{} {}".format(test_case+1, bnsStr))
'''