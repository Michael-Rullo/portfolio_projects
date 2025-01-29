from turtle import Screen
import turtle as tu
import tkinter as tk

def threenp1(n):
    count = 0
    while n > 1.0:
        count += 1
        if n % 2 == 0:
            n = int(n / 2)
        else:
            n = int(3 * n + 1)
    return count
def threenp1range(upper_limit):
    objs_in_sequence = {}
    for i in range(2, upper_limit+1):
        n = threenp1(i)
        objs_in_sequence[i] = n
    return objs_in_sequence
def graph_coords(objs_in_sequence):
    max_so_far = 0
    for key, value in objs_in_sequence.items():
        if value > max_so_far:
            max_so_far = value
            score.clear()
        score.penup()
        score.ht()
        score.goto(0, max_so_far+1)
        score.write('Maximum so far: ')
        screen.setworldcoordinates(0, 0, key+10, max_so_far+10)
        draw.pendown()
        draw.goto(key, value)
        draw.penup()
        draw.goto(key, 0)
        draw.write(key)
        draw.goto(0, value)
        draw.write(value)
        draw.goto(key, value)
        
screen = Screen()
screen.setup()
screen.colormode(255)
screen.bgcolor('light blue')

score = tu.Turtle()
score.speed(0)

draw = tu.Turtle()
draw.ht()
draw.penup()
draw.speed(0)

while True:
    tu.TK.messagebox.showinfo(title="Graph", message="Input a number 2 or beyond")
    num = int(tu.numinput('Input', 'Input a number 2 or beyond: '))
    if num >= 2:
        break
    else:
        tu.TK.messagebox.showinfo(title="Prediction", message='This was not a valid input. Please try again')
graph_coords(threenp1range(num))

screen.exitonclick()