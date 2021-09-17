from cs50 import get_float

def main():
    owed = get_owed()
    coins = calc_coins(owed)
    print(coins)


def get_owed():
    while True:
        owe = get_float("Change owed: ")
        if owe>=0:
            break
    return owe


def calc_coins(owed):
    coins = 0
    amount = round(owed*100)
    while amount>0:
        if amount>=25:
            amount -= 25
        elif amount>=10:
            amount -= 10
        elif amount>=5:
            amount -= 5
        else:
            amount -= 1
        coins += 1
    return coins



main ()