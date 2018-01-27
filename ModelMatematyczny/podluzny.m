clear
clc
load("../xplane2csv/matlab_workspace.mat");
% Identyfikacja kana³u pod³u¿nego

%   in: dH, out: q [rad/s]
range = 9700:10200;
x = elev_yoke1(range);
y = Q_rad_s(range);
q = identyfikacja(x, y, 1/50, 2, 0)

figure(2)
subplot(2,1,1)
lsim(q, x, 0:1/50:10)
title("Prêdko¶æ k±towa pochylania (model)")
grid on
subplot(2,1,2)
plot(x)
hold on
plot(y)
title("Prêdko¶æ k±towa pochylania (zarejestrowane dane)")
grid on

%   in: dH, out: theta [rad]
integral = tf([1], [1 0]);
theta = q * integral
figure(3)
step(theta)
title("theta")

%   in: dH, out: w [m/s]
G = 9.81;
range = 9700:10200;
x = elev_yoke1(range);
y = Gload_norml(range) * G;
w = identyfikacja(x, y, 1/50, 2, 0) * integral

figure(4)
subplot(2,1,1)
title("w")
lsim(w, x, 0:1/50:10)
subplot(2,1,2)
plot(x)
hold on
plot(cumtrapz(y)/50)

%   in: dH, out: u [m/s]
G = 9.81;
range = 9700:10200;
x = elev_yoke1(range);
y = Gload_axial(range) * G;
u = identyfikacja(x, y, 1/50, 2, 0) * integral

figure(5)
subplot(2,1,1)
title("u")
lsim(u, x, 0:1/50:10)
subplot(2,1,2)
plot(x)
hold on
plot(cumtrapz(y)/50)