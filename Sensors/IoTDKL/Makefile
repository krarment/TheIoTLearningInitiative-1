all: lcd lcd_temp

lcd:
	g++ -lmraa -lupm-i2clcd -lupm-mpl3115a2 -I/usr/include/upm/ lcd.cpp -o lcd
lcd_temp:
	g++ -lmraa -lupm-i2clcd -lupm-mpl3115a2 -I/usr/include/upm/ lcd_temp.cpp -o lcd_temp
clean:
	rm lcd lcd_temp
