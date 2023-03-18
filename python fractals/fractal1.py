from turtle import *

lenght = 10
angle = 90

speed(100)

def draw_path(path):
    left(angle)
    for symbol in path:
        if symbol == 'F':
            forward(lenght)
        elif symbol == '-':
            left(angle)
        elif symbol == '+':
            right(angle)

def apply_rule(path):
    rule="F-F+F+FF-F-F+F"

    return path.replace("F", rule)

path= "F-F-F-F"

path = apply_rule(path)
path = apply_rule(path)
draw_path(path)

exitonclick()