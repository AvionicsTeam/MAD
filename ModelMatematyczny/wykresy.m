figure(1)

subplot(3, 1, 1)
plot(elev_yoke1)
grid on
ylabel("Wychylenie steru wysoko¶ci")

subplot(3, 1, 2)
plot(Q_rad_s)
grid on
ylabel("q [rad/s]")

subplot(3, 1, 3)
plot(trim_ailrn)
grid on
ylabel("MARKER")