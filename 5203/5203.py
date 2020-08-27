class BabyJin:
    def __init__(self):
        self.cards={}
    def add_and_result(self, card):
        cards = self.cards
        if card in cards: # 받은 카드가 이미 존재할 경우 triplet 찾기
            cards[card] += 1
            if cards[card] >= 3: # triplet
                return True
        else: # 존재하지 않을 때 run 찾기
            cards[card] = 1
            if card - 1 in cards: # 1작은 수가 존재하는가?
                if card - 2 in cards or card + 1 in cards: # 2작은 수가 존재하거나 1큰 수가 존재하는가?
                    return True # run (-2, -1, 0) or (-1, 0, +1)
            elif card + 1 in cards and card + 2 in cards:
                return True # run (0, +1, +2)
        return False

T = int(input())

for tc in range(1, T+1):
    player1 = BabyJin()
    player2 = BabyJin()

    numberList = list(map(int, input().split())) # 일단 12개의 숫자를 입력받음
    result = 0 # 초기화 값. 게임이 끝나지 않으면 0을 출력
    for i in range(12):
        #i가 짝수면 player1에게 카드를 주고, 게임이 끝나는 조건을 만족하면 result를 1로 바꾸고 게임을 끝냄
        if i%2 == 0 and player1.add_and_result(numberList[i]):
            result = 1
            break
        #i가 홀수면 player2에게 카드를 주고, 게임이 끝나는 조건을 만족하면 result를 2로 바꾸고 게임을 끝냄
        elif i%2 == 1 and player2.add_and_result(numberList[i]):
            result = 2
            break
    print("#%d %d"%(tc, result))