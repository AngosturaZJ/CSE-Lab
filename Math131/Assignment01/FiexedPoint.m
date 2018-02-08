g = @(x) exp(-x);
x0 = 0.25;
tol = 10^(-10);
N = 100;

[c, n, err] = fixed_point_iteration(g, x0, tol, N);

% c is the answer of input equation, n is number of iteration for
% calculating the acceptable answer, and err is the error rate for the
% acceptable answer
% g is function, x0 is the guess of answer, tol is the accecptable error 
% rate, and N is the max number of iteration
function[c,n,err] = fixed_point_iteration(g,x0,tol,N)

n = 0; % initial the number of iteration to 0

% keep finding root when number of iteration is less than or equal to
% maximum number of iteration
while n < N
    
    p = g(x0); % calculate the value of g(current x)
    err = abs(p-x0); % calculate the error between g(current x) and last x
    
    if err <= tol 
        % if error is less than or equal to acceptable error, answer found
        c = x0; % assign current x to c as answer
        break; % the method is done, jump out of the loop
    else % error is greater than acceptable error, run following codes
        % number of iteration increase 1 since the while loop will continue
        n = n + 1;
        x0 = p; % update x, new x = f(current x)
    end
end
% plot the function
x = linspace(-1, 1, 1000);
plot(x, g(x));
hold on;
% plot y = x
plot(x,x);
end
% my initial guess is 0.25
% this program takes 40 itertions to find answer