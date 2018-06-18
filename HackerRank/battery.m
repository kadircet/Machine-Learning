data = load('battery.txt');
x = data(:,1); y=data(:,2);
figure;
plot(x,y,'rx','MarkerSize', 10);
pause;
