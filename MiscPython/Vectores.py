import numpy as np
import matplotlib.pyplot as plt

plt.style.use('seaborn')

#Variables
mu_0 = 4*np.pi*10e-7 #Permitividad del espacio libre
r0 = [0,0] #Posicion del dipolo magnetico
m = [0,0.1] #Momento magnetico

# Cuadricula
x = np.linspace(-1,1,20) #Lista de valores x
y = np.linspace(-1,1,20) #Lista de valores y
X, Y = np.meshgrid(x,y) #Matriz

#Desplazar los valores
X_disp = X - r0[0]
Y_disp = Y - r0[1]

#Formulas
const = mu_0/(4*np.pi)
mag_XY = np.sqrt(X_disp**2 + Y_disp**2)
X_Unit = X_disp/mag_XY #R con gorrito x
Y_Unit = Y_disp/mag_XY #R con gorrito y

r = np.sqrt(X_disp**2 + Y_disp**2)
m_dot_R = m[0]*X_Unit + m[1]*Y_Unit

B_x = const*((3*X_Unit*m_dot_R - m[0])/(r**3))
B_y = const*((3*Y_Unit*m_dot_R - m[1])/(r**3))

mag_B = np.sqrt(B_x**2 + B_y**2)

plt.figure(figsize=(16,8))

plt.subplot(1,2,1)
plt.quiver(x,x,B_x/mag_B,B_y/mag_B)
plt.title('Vectores Unitarios del Campo Magnético')

plt.subplot(1,2,2)
plt.streamplot(X,Y,B_x,B_y)
plt.title('Lineas de trayectoria del campo Magnético')

plt.show()