# Initialization
from turtle import Screen
import turtle as tu
import random as rand
import math
import tkinter
p = 1
listx = []
listy = []
p1score = 0
p2score = 0
greenhit = (0, 255, 120)
greenmiss = (0, 110, 55)
purplehit = (34, 0, 255)
purplemiss = (10, 0, 80)
winner = 0
draw = tu.Turtle()
setup = tu.Turtle()
size = tkinter.Tk()
width = size.winfo_screenwidth()
height = size.winfo_screenheight()
screen = Screen()
screen.setup(width, height)
screen.bgcolor('light blue')
screen.setworldcoordinates(-width/2, -height/2, width/2, height/2)
screen.colormode(255)
setup.speed(0)
setup.ht()
setup.penup()
setup.fillcolor('gray')
draw.speed(0)
draw.ht()
draw.penup()
# Functions
def p1throw(x, y, p1score):
    dist = math.hypot(x, y)
    draw.goto(x, y-10)
    if dist <= (height/2):
        p1score += 1
        draw.color(greenhit)
    else:
        draw.color(greenmiss)
    draw.pendown()
    draw.begin_fill()
    draw.circle(5)
    draw.end_fill()
    draw.penup()
    return p1score
def p2throw(x, y, p2score):
    dist = math.hypot(x, y)
    draw.goto(x, y-10)
    if dist <= (height/2):
        p2score += 1
        draw.color(purplehit)
    else:
        draw.color(purplemiss)
    draw.pendown()
    draw.begin_fill()
    draw.circle(5)
    draw.end_fill()
    draw.penup()
    return p2score
# Script/Run
setup.goto(0, -height/2)
setup.pendown()
setup.begin_fill()
setup.circle(height/2)
setup.end_fill()
setup.penup()
setup.penup()
setup.goto(-height/2, 0)
setup.st()
setup.pendown()
setup.goto(height/2, 0)
setup.penup()
setup.goto(0, height/2)
setup.pendown()
setup.goto(0, -height/2)
while p == 1:
    tu.TK.messagebox.showinfo(title="Prediction", message="Please guess which color will win!")
    guess = tu.textinput('Input', 'Input prediction as "green" or "purple" :')
    if (guess.lower() == 'green') or (guess.lower() == 'purple'):
        guess = guess.lower()
        break
    else:
        tu.TK.messagebox.showinfo(title="Prediction", message='This was not a valid input. Please try again')
for z in range(10):
    x = rand.randint(round(-width/2), round(width/2))
    y = rand.randint(round(-height/2), round(height/2))
    p1score = p1throw(x, y, p1score)
    x = rand.randint(round(-width/2), round(width/2))
    y = rand.randint(round(-height/2), round(height/2))
    p2score = p2throw(x, y, p2score)
winner = 0
if p1score > p2score:
    winner = 'green'
    tu.color(winner)
    tu.write('Player One (Green) wins!', True, 'center', ('Arial', 30, 'normal'))
elif p1score < p2score:
    winner = 'purple'
    tu.color(winner)
    tu.write('Player Two (Purple) wins!', True, 'center', ('Arial', 30, 'normal'))
else:
    tu.write('Its a tie', True, 'center', ('Arial', 30, 'normal'))
tu.penup()
tu.goto(0,-40)
tu.pendown()
if winner == guess:
    tu.write('  You guessed correct', False, 'center', ('Arial', 30, 'normal'))
else:
    tu.write('  You guessed incorrectly', False, 'center', ('Arial', 30, 'normal'))
screen.exitonclick()