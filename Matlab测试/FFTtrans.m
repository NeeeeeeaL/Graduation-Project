clear all,close all;
A=imread('15.5blue_cutted.bmp');
A=rgb2gray(A);
figure,imshow(A)
C=A(100,:);
figure,plot(C)

% f=fft2(A);        %����Ҷ�任
% f=fftshift(f);      %ʹͼ��Գ�
% r=real(f);          %ͼ��Ƶ��ʵ��
% i=imag(f);          %ͼ��Ƶ���鲿
% margin=log(abs(f));      %ͼ������ף���log������ʾ
% phase=log(angle(f)*180/pi);     %ͼ����λ��
% l=log(f);           
% subplot(2,2,1),imshow(A),title('Դͼ��');
% %subplot(2,2,2),imshow(l,[]),title('ͼ��Ƶ��');
% subplot(2,2,3),imshow(margin,[]),title('ͼ�������');
% subplot(2,2,4),imshow(phase,[]),title('ͼ����λ��');

B=fftshift(fft2(A)); % ���ж�ά��ɢ����Ҷ�任��
figure(1); 
mesh(abs(B))
figure(2);
figure (3)
subplot(231)
%imshow(A);
title('ԭʼͼ��');
%figure (4)
subplot(232)
imshow(abs(B),[ ]);
title('ԭʼƵ��ͼ');
%figure (5)
subplot(233)
imshow(log(abs(B)),[ ]);
title('ȡ�������Ƶ��ͼ');
%figure (6)
subplot(234)
imshow(angle(B),[ ]);
%figure (3)
%mesh(angle(B))
title('��λͼ');
%figure (4)
subplot(235)
imshow(real(B),[ ]);
title('ʵ��ͼ');
subplot(236)
imshow(imag(B),[ ]);
title('�鲿ͼ');
colormap(jet(64)) %��ͼƬ��ɫ