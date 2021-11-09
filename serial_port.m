close all
clc
clear all

delete(instrfind({'Port'},{'COM3'}));
puerto=serial('COM3');
puerto.BaudRate=9600;
warning('off','MATLAB:Serial:fscanf:unsuccesfulRead');
fopen(puerto);

    for i=1:100
    valor = str2num(fscanf(puerto))

      plot(i,valor,'*r')
      hold on
     
     drawnow
    end

   