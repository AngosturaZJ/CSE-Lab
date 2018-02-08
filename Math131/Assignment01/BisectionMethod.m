f = @(x)(2.*x.^3+3.*x-1).*cos(x)-x;
a = -1;
b = 1;
tol = 10^-5;
N = 100;

g = solve(@(x)(2.*x.^3+3.*x-1).*cos(x)-x,0);
fprintf("g = %.12f", g);

[c, n, err] = bisection_method(f, a, b, tol, N);

% c is the answer of input equation, n is number of iteration for
% calculating the acceptable answer, and err is the error rate for the
% acceptable answer
% f is function, a is the beginning of interval, b is the end of interval,
% tol is the accecptable error rate, and N is the max number of iteration
function [c,n,err] = bisection_method(f,a,b,tol,N)

format long;
n = 0; % initial the number of iteration
err = 1; % initial the error rate

% keep iterating as n doesn't reach to the max number of iteration and
% error rate is greater than acceptable error rate
while n < N && err > tol
    
    mid = (a+b)/2; % find midpoint of interval
    fp = f(mid); % calculate f(midpoint)
    err = abs(a - b)/2; % find error rate of current evaluation
    fa = f(a); % calculate f(begin of current interval)
    fb = f(b); % calculate f(end of current interval)
    
    % check the signs of f(a) and f(b), run bisection method if they have
    % oppsite signs
    if fa*fb <= 0
        if fp == 0 || err <= tol
            % as f(p) is 0 or error rate of f(p) is less than or equal to
            % acceptable error rate, p is the answer for this problem
            c = mid; % assign current mid to c as answer
            break; % jump out of the while loop
        elseif fp*fa > 0 
            % as f(p) and f(a) have the same sign go to second half part of
            % interval, and keep looping in the while loop
            a = mid;
            n = n + 1; % add 1 for every iteration
        else
            % as f(p) and f(a) don't have the same sign go to first half
            % part of interval and keep looping in the while loop
            b = mid;
            n = n + 1; % add 1 for every iteration
        end
    else
        % report error when f(a) and f(b) do not have opposite signs
        disp("f(a) and f(b) has the same sign, cannot use bisection method")
    end
end
% define the interval of x
x = linspace(-1, 1, 1000);
% plot the function
plot(x, f(x));
hold on;
% draw a horizontal line of y = 0
y = 0;
line([-1, 1], [y, y]);
end

% this function takes 17 iterations
% the error bound is 7.6294e-06
% Following two lines of code is used to find value of x by built-in
% function of MATLAB, and then print the value
% g = solve(@(x)(2.*x.^3+3.*x-1).*cos(x)-x,0);
% fprintf("g = %.12f", g);
% the root for this program is 0.4386 
% and MATLAB's answer is 0.4385674577098013167563577921244
