fprintf('Practica Matlab 2\n');

%Jose Granger Salgado - A01023661

% Variables

k = 0.23;
l = 1;
g = 9.81;
a = 0.5;
M = 1;
F0 = 1;

%Variables Ejercio 1

x1o = 0;
v1o = 2;
x2o = 0;
v2o = 7;

%Ejericio 1

[t,x] = ode45(@(t,x) [x(2); (-g/l)*sin(x(1))], [0 10], [x1o,v1o]);
[t2,x2] = ode45(@(t2,x2) [x2(2); (-g/l)*sin(x2(1))], [0 10], [x2o,v2o]);

figure(1)
plot(t,x(:,1))
hold on
plot(t2,x2(:,1))

%-----------------------------------------------------------------
clear all;

k = 0.23;
l = 1;
g = 9.81;
a = 0.5;
M = 1;
F0 = 1;

%Variables Ejercio 2

x1o = 0;
v1o = 2;
x2o = 0;
v2o = 7;

%Ejercicio 2

[t3,x3] = ode45(@(t3,x3) [x3(2); (-g/l)*sin(x3(1))-a*(x3(2))], [0 10], [x1o,v1o]);
[t4,x4] = ode45(@(t4,x4) [x4(2); (-g/l)*sin(x4(1))-a*(x4(2))], [0 10], [x2o,v2o]);

figure(2)
plot(x3(:,2),x3(:,1))
hold on
plot(x4(:,2),x4(:,1))

%-----------------------------------------------------------------
clear all;

k = 0.23;
l = 1;
g = 9.81;
a = 0.5;
F0 = 5;
M = 1;
w = sqrt(k/M);

x1o = 0;
v1o = 2;
x2o = 0;
v2o = 7;

symb1 = w+2;
symb2 = w-2;
symb3 = w;





%Ejercicio 3

[t5,x5] = ode45(@(t5,x5) [x5(2); (-k*x5(1)+(F0*sin(symb1*t5)))/M], [0 100], [x1o,v1o]);
[t6,x6] = ode45(@(t6,x6) [x6(2); (-k*x6(1)+(F0*sin(symb2*t6)))/M], [0 100], [x1o,v1o]);
[t7,x7] = ode45(@(t7,x7) [x7(2); (-k*x7(1)+(F0*sin(symb3*t7)))/M], [0 100], [x1o,v1o]);
[t8,x8] = ode45(@(t8,x8) [x8(2); (-k*x8(1)+(F0*sin(symb1*t8)))/M], [0 100], [x2o,v2o]);
[t9,x9] = ode45(@(t9,x9) [x9(2); (-k*x9(1)+(F0*sin(symb2*t9)))/M], [0 100], [x2o,v2o]);
[t0,x0] = ode45(@(t0,x0) [x0(2); (-k*x0(1)+(F0*sin(symb3*t0)))/M], [0 100], [x2o,v2o]);


% Firgure 3

 figure(3)
    plot(t5, x5(:,1))
    plot(t8, x8(:,1))
    hold on
    figure(4)
    plot(t6, x6(:,1))
    plot(t9, x9(:,1))
    hold on
    figure(5)
    plot(t7, x7(:,1))
    plot(t0, x0(:,1))
    hold on


