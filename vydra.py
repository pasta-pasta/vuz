import random

def dynamic_dice_calc(dice):
    """
    Подсчитывает количество возможных исходов для заданного набора кубиков.
    """
    outcomes = {0: 1}  
    
    for count, sides in dice:
        for _ in range(count):
            new_outcomes = {}
            for prev_sum in outcomes.keys():
                for roll in range(1, sides + 1):
                    new_sum = prev_sum + roll
                    if new_sum not in new_outcomes:
                        new_outcomes[new_sum] = 0
                    new_outcomes[new_sum] += outcomes[prev_sum]
            outcomes = new_outcomes  

    return outcomes, sum(outcomes.values())

dice = [(18, 6), (4, 10), (10, 12), (3, 20)]
outcomes, all = dynamic_dice_calc(dice)

for outcome, count in outcomes.items():
    print(f'Шанс выпадения {outcome}: {count / all:.8%}')