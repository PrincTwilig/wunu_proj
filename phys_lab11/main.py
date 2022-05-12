import matplotlib.pyplot as plt
import numpy as np
# libraries to make smooth line
from scipy.interpolate import make_interp_spline, BSpline

def draw_graph(x1, y1, x2, y2):
    # draw a line x and y
    ax = plt.gca()
    ax.axhline(y=0, color='k')
    ax.axvline(x=0, color='k')
    plt.plot(x1, y1)
    plt.plot(x2, y2)
    # name the graph sides
    plt.xlabel('U')
    plt.ylabel('I')
    # show the graph
    plt.show()

def normalize(x1, y1, x2, y2, spisk):
    # normalize numbers to spisk
    # self.Ce[i] = self.Ce[i] * (self.spisk / 100) + self.Ce[i]
    for i in range(len(x1)):
        x1[i] = x1[i] * (spisk / 100) + x1[i]
        y1[i] = y1[i] * (spisk / 100) + y1[i]
        x2[i] = x2[i] * (spisk / 100) + x2[i]
        y2[i] = y2[i] * (spisk / 100) + y2[i]
    draw_graph(x1, y1, x2, y2)


x1 = [0, 0.2, 0.4, 0.6, 0.8]
y1 = [0, 1, 4, 8, 12]
x2 = [0, 0.2, 0.4, 0.6, 0.8]
y2 = [0, 7, 7, 7, 7]

spisk = int(input("Enter the spisk: "))
normalize(x1, y1, x2, y2, spisk)