from turtle import *

lenght = 5
angle = 90

path = "-F"

speed(2000)

def draw_path(path):
    left(angle)
    for symbol in path:
        if symbol =='F':
            forward(lenght)
        elif symbol == '-':
            right(angle)
        elif symbol == '+':
            left(angle)

def apply_rule(path):
    rule="F+F-F-F+F"

    return path.replace("F", rule)


path = apply_rule(path)
path = apply_rule(path)
path = apply_rule(path)
path = apply_rule(path)

draw_path(path)

exitonclick()