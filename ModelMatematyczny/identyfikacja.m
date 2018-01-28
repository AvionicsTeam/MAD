% x - wektor wej¶ciowy
% y - wektor odpowiedzi
% Ts - okres próbkowania
% pol - liczba biegunów transmitancji
function Gz = identyfikacja(x, y, Ts, pol, zero)
    id = iddata(y, x, Ts);
    Gz = tfest(id, pol, zero);
    Gz = tf(Gz.Numerator, Gz.Denominator);
end