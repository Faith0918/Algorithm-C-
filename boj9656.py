# if stone == 1, a player is the loser
# if stone == 2, a player is the winner
# if stone == 3, a player is the loser
# if stone == 4, a player is the winner
# if stone == 5, SK player is the loser
# if stone == 6, a player should take 3 to leave 3. If the player takes 1 and leave 5 stones, next would take 3 to leave 2 than, the next will take 1
# player should always leave odd number of stones to win. 

n = int(input())
if n%2 == 0:
    print("SK")
else:
    print("CY")