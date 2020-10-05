import numpy as np
import matplotlib.pyplot as plt
from tqdm import tqdm

grav = 9.81
m = 0.01
mu = 1e6
mu_0 = 4*np.pi*1e-7
a = 0.08
R = 9e-5

k = (9*(mu*mu_0)**2*a**4)/(4*R)


def p(x):
    return (x**2)/(x**2+a**2)**(5/2)


def f(t, x, y):
    return y


def g(t, x, y):
    return -grav-(k/m)*p(x)*y


t_0 = 0
t_f = 6
h = 0.01
N = int((t_f-t_0)/h)
t = np.linspace(t_0, t_f, N)

x_0 = 10
y_0 = 0


all_xs = []
all_ys = []
Fz = []

x_n = x_0
y_n = y_0

for this_t in tqdm(t):
    all_xs.append(x_n)
    all_ys.append(y_n)
    Fz.append(-k*p(x_n)*y_n)
    k_x1 = f(this_t, x_n, y_n)
    k_y1 = g(this_t, x_n, y_n)
    k_x2 = f(this_t + 0.5*h, x_n + 0.5*h*k_x1, y_n + 0.5*h*k_y1)
    k_y2 = g(this_t + 0.5*h, x_n + 0.5*h*k_x1, y_n + 0.5*h*k_y1)
    k_x3 = f(this_t + 0.5*h, x_n + 0.5*h*k_x2, y_n + 0.5*h*k_y2)
    k_y3 = g(this_t + 0.5*h, x_n + 0.5*h*k_x2, y_n + 0.5*h*k_y2)
    k_x4 = f(this_t + h, x_n + h*k_x3, y_n + h*k_y3)
    k_y4 = g(this_t + h, x_n + h*k_x3, y_n + h*k_y3)
    x_nplus1 = x_n + (h/6)*(k_x1 + 2*k_x2 + 2*k_x3 + k_x4)
    y_nplus1 = y_n + (h/6)*(k_y1 + 2*k_y2 + 2*k_y3 + k_y4)
    x_n = x_nplus1
    y_n = y_nplus1

plt.figure(figsize=(12, 4))

plt.subplot(1, 2, 1)
plt.plot(t, all_xs)
plt.title("Altura de Dipolo con Frenado Magnético")
plt.xlabel("Tiempo [s]")
plt.ylabel("Altura [m]")

plt.subplot(1, 2, 2)
plt.plot(t, all_ys)
plt.title("Velocidad de Dipolo con Frenado Magnético")
plt.xlabel("Tiempo [s]")
plt.ylabel("Velocidad [m/s]")

plt.figure(figsize=(6, 4))
plt.plot(t, Fz)
plt.title("Fuerza")
plt.xlabel("Tiempo [s]")
plt.ylabel("Fuerza")
plt.show()
