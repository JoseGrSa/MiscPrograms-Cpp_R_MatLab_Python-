fprintf('Oscilador armónico simple y amortiguado\n');

%Jose Granger Salgado - A01023661

%Variables

M = input('Masa:');
A = input('Amplitud de movimiento:');
k = input('Constante de restitución:');
w = (k/M)^0.5;

valores_iniciales = [0,A];

fprintf('La frecuencia angular es (en rad/s): %.2f',round(w,2));

y0 = 0;
xtiempo = 0:1:10;

operacion_1 = 3*M*w;
operacion_2 = 2*M*w;
operacion_3 = 1*M*w;

tsegu = [0:1:100];
xpos = @(t) A*cos(w*t);
xder = @(t) -A*w*sin(w*t);
t = 0:0.1:10;

formula_1 = @(t1,x) [-k*xpos(t1)];

[t1, x] = ode45(formula_1, t, y0 );

longitud = length(t);

%Formulas

formula_2 = @(t2,x1) [-k*xpos(t2)-operacion_1*xder(t2)];%beta > 2
[t2, x1] = ode45(formula_2, tsegu, y0 );
formula_3 = @(t3,x2) [-k*xpos(t3)-operacion_2*xder(t3)];%beta = 2
[t3, x2] = ode45(formula_3, tsegu, y0 );
formula_4 = @(t4,x3) [-k*xpos(t4)-operacion_3*xder(t4)];%beta < 2
[t4, x3] = ode45(formula_4, tsegu, y0 );

%Grafica_3
figure(3)
plot(tsegu,x1)
title('Grafica_3')
hold on
plot(tsegu,x2)
hold on
plot(tsegu,x3)
legend('Caso > 2','Caso = 2','Caso <2')

%Tabla

tabla = fopen('Tabla_1.txt','w');
fprintf(tabla,'Posicion   Velocidad\n');
for a = 0:0.1:10
    fprintf(tabla,'%2.2f  ||  %2.2f\n',xpos(a),xder(a));
end

%Tabla 2

tabla2 = fopen('Tabla_2.txt','w');
fprintf(tabla2,'Tiempo     X\n');

%Grafica 1

figure(1)
plot(t,xpos(t))
title('Grafica_1')
hold on
plot(t,xder(t))
legend('x(t)','v(t)')

for b = 1:1:101
    fprintf(tabla2,'%2.2f  ||  %2.2f\n',t(b),x(b));
end

%Grafica_2

figure(2)
plot(t,x)
title('Grafica_2')
hold on
plot(t,xpos(t))
legend('v(t)','x(t)')