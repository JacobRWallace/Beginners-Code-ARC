import random
import os

min = 1
max = 100
is_running = True
ranum = random.randint(min, max)
guesses = 0
os.system('cls')

while(is_running):
    print(f"Guess #: {guesses}")
    input1 = int(input(f'Guess the number from {min}-{max}: '))
    if(input1==ranum):
        os.system('cls')
        print("You won!")
        print(f"Guesses: {guesses}")
        print(f"Number was: {ranum}")
        is_running = False
    elif(input1<min or input1>max):
        os.system('cls')
        print("Input not within range!")
    elif(input1>ranum):
        os.system('cls')
        print("Go lower!")
        guesses = guesses + 1
    elif(input1<ranum):
        os.system('cls')
        print("Go higher!")
        guesses = guesses + 1
    else:
        os.system('cls')
        print("Error!")
        break