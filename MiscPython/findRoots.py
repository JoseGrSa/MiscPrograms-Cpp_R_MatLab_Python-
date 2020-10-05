import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import bisect, newton
plt.style.use('ggplot')


def f(x):
    return x*np.cos(x)+1


def f1(x):
    return x-np.cos(x)


def f2(x):
    return x*np.log10(x)-1.2


def f3(x):
    return np.exp(0.3*x)-(x**2)+4


def f4(x):
    return 2*np.cos(x)-(np.sqrt(x)/2)-1


def bisection_method(f, a, b):
    while (b-a)/2 >= 2e-12:
        c = (a + b)/2
        if (f(a) < 0 and f(c) > 0) or (f(a) > 0 and f(c) < 0):
            b = c
        elif (f(b) < 0 and f(c) > 0) or (f(b) > 0 and f(c) < 0):
            a = c
        if f(c) == 0:
            return c
    return c


def differential(f, x, dx=1e-12):
    return (f(x+dx)-f(x))/dx


def newton_method(f, x_0):
    Xn = x_0
    while True:
        Xn_1 = Xn - (f(Xn)/differential(f, Xn))
        if abs(Xn - Xn_1) < 2e-12:
            return Xn_1
        Xn = Xn_1


# Ejercicio 1
res1_biseccion = bisection_method(f1, -5, 5)
res1_newton = newton_method(f1, 0.5)
print('1. Metodo de Biseccion:', res1_biseccion)
print('1. Metodo de Newton:', res1_newton)

x = np.linspace(-5, 5, 50)
plt.figure(1, figsize=(12, 4))
plt.plot(x, f1(x), color='black')
plt.plot(res1_biseccion, f1(res1_biseccion), 'o', color='red', ms=10)
plt.plot(res1_newton, f1(res1_newton), 'o', color='blue', ms=7)
title = plt.title('Gráfico de f(x) en el intervalo de [-5,5]')

# Ejercicio 2
res2_biseccion = bisection_method(f2, 1, 5)
res2_newton = newton_method(f2, 2.5)
print('2. Metodo de Biseccion:', res2_biseccion)
print('2. Metodo de Newton:', res2_newton)

x2 = np.linspace(1, 5, 50)
plt.figure(2, figsize=(12, 4))
plt.plot(x2, f2(x2), color='black')
plt.plot(res2_biseccion, f2(res2_biseccion), 'o', color='red', ms=10)
plt.plot(res2_newton, f2(res2_newton), 'o', color='blue', ms=7)
title = plt.title('Gráfico de f(x) en el intervalo de [1,5]')

# Ejercicio 3
res3_biseccion1 = bisection_method(f3, -3, -1)
res3_biseccion2 = bisection_method(f3, 1, 3)
res3_biseccion3 = bisection_method(f3, 18, 20)
res3_newton1 = newton_method(f3, -3)
res3_newton2 = newton_method(f3, 1)
res3_newton3 = newton_method(f3, 18)
print(
    f'3. Metodo de Biseccion: raiz 1) {res3_biseccion1} | raiz 2) {res3_biseccion2} | raiz 3) {res3_biseccion3}')
print(
    f'3. Metodo de Newton:    raiz 1) {res3_newton1}| raiz 2) {res3_newton2}   | raiz 3) {res3_newton3}')

x3 = np.linspace(-5, 21, 200)
plt.figure(3, figsize=(12, 4))
plt.plot(x3, f3(x3), color='black')
plt.plot(res3_biseccion1, f3(res3_biseccion1), 'o', color='red', ms=10)
plt.plot(res3_newton1, f3(res3_newton1), 'o', color='blue', ms=7)
plt.plot(res3_biseccion2, f3(res3_biseccion2), 'o', color='red', ms=10)
plt.plot(res3_newton2, f3(res3_newton2), 'o', color='blue', ms=7)
plt.plot(res3_biseccion3, f3(res3_biseccion3), 'o', color='red', ms=10)
plt.plot(res3_newton3, f3(res3_newton3), 'o', color='blue', ms=7)
title = plt.title('Gráfico de f(x) en el intervalo de [-5,21]')

# Ejercicio 4
res4_biseccion = bisection_method(f4, 0, 2)
res4_newton = newton_method(f4, 0)
print('4. Metodo de Biseccion:', res4_biseccion)
print('4. Metodo de Newton:', res4_newton)

x4 = np.linspace(0, 10, 200)
plt.figure(4, figsize=(12, 4))
plt.plot(x4, f4(x4), color='black')
plt.plot(res4_biseccion, f4(res4_biseccion), 'o', color='red', ms=10)
plt.plot(res4_newton, f4(res4_newton), 'o', color='blue', ms=7)
title = plt.title('Gráfico de f(x) en el intervalo de [0,10]')
plt.show()
