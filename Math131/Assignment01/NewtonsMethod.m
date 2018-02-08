f = @(x) atan(x)-1;
fp = @(x) 1./(1 + x.^2);
x0 = 2;
tol = 1e-8;
N = 100;

[c, n, err] = newtons_method(f, fp, x0, tol, N);

% c is the answer of input equation, n is number of iteration for
% calculating the acceptable answer, and err is the error rate for the
% acceptable answer
% f is function, fp is derivative of f, x0 is the initial guess tol is the 
% accecptable error rate, and N is the max number of iteration
function [c,n,err] = newtons_method(f,fp,x0,tol,N)

% initializing...
n = 0;
err = 1;

% keep using newton's method to find the answer of equation when number of
% iteration is less than maximum number of iteration and error is greater
% than acceptable error
while n < N && err > tol
    
    % increase n by 1 for every time the while loop is executed
    n = n + 1;
    % find out new value 
    c = x0 - f(x0)./fp(x0);
    % calculate error
    err = abs(c - x0);
    
    % the function will finish when error is less than acceptable error or
    % c = f(c)
    if err < tol %|| c == f(c)
        break
    else
        % update new value to x0 if new value is not the acceptable answer
        x0 = c;
    end
end
% set x-axis interval
x = linspace(-10, 10, 1000);
% plot the function
plot(x, f(x));
hold on;
% plot y = 0
y = 0;
line([-10, 10], [y, y]);
end
% this method is convergence when initial guess is 2
% when ititial guess is -2, the method cannot find answer, because it is divergence