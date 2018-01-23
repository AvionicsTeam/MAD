clear
clc
load("../xplane2csv/matlab_workspace.mat");
% Identyfikacja kana³u pod³u¿nego

%   in: dH, out: q [rad/s]
range = 9700:10200;
x = elev_yoke1(range);
y = Q_rad_s(range);
q = identyfikacja(x, y, 1/50, 2, 0);

figure(2)
subplot(2,1,1)
lsim(q, x, 0:1/50:10)
title("q")
subplot(2,1,2)
plot(x)
hold on
plot(y)

%   in: dH, out: theta [rad]
theta = q * tf([1], [1 0])
figure(3)
step(theta)
title("theta")

%   in: dH, out: u [m/s]
range = 9700:10200;
x = elev_yoke1(range);
y = (Vind_kias(range)-y(1)) * 0.514444444;     % knot to mps conversion
u = identyfikacja(x, y, 1/50, 2, 0);

figure(4)
subplot(2,1,1)
title("u")
lsim(u, x, 0:1/50:10)
subplot(2,1,2)
plot(x)
hold on
plot(y)