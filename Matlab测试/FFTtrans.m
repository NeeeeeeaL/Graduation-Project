clear all,close all;
A=imread('15.5blue_cutted.bmp');
A=rgb2gray(A);
figure,imshow(A)
C=A(100,:);
figure,plot(C)

% f=fft2(A);        %傅里叶变换
% f=fftshift(f);      %使图像对称
% r=real(f);          %图像频域实部
% i=imag(f);          %图像频域虚部
% margin=log(abs(f));      %图像幅度谱，加log便于显示
% phase=log(angle(f)*180/pi);     %图像相位谱
% l=log(f);           
% subplot(2,2,1),imshow(A),title('源图像');
% %subplot(2,2,2),imshow(l,[]),title('图像频谱');
% subplot(2,2,3),imshow(margin,[]),title('图像幅度谱');
% subplot(2,2,4),imshow(phase,[]),title('图像相位谱');

B=fftshift(fft2(A)); % 进行二维离散傅立叶变换；
figure(1); 
mesh(abs(B))
figure(2);
figure (3)
subplot(231)
%imshow(A);
title('原始图像');
%figure (4)
subplot(232)
imshow(abs(B),[ ]);
title('原始频谱图');
%figure (5)
subplot(233)
imshow(log(abs(B)),[ ]);
title('取对数后的频谱图');
%figure (6)
subplot(234)
imshow(angle(B),[ ]);
%figure (3)
%mesh(angle(B))
title('相位图');
%figure (4)
subplot(235)
imshow(real(B),[ ]);
title('实部图');
subplot(236)
imshow(imag(B),[ ]);
title('虚部图');
colormap(jet(64)) %给图片上色