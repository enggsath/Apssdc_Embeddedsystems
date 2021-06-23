//hardware declaration

#define lcd P2
sbit Rs=P3^0;
sbit En=P3^1;

//function declaration

void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_string(unsigned char[]);
void lcd_delay(unsigned int);

//function defination

void lcd_init(void)
{
	lcd_cmd(0x38); //init lcd as 8-bit display
	lcd_cmd(0x01); //clear lcd screen
	lcd_cmd(0x02); //return to home
	lcd_cmd(0x0c); //display on cursor off
	lcd_cmd(0x06); //increment cursor
}

void lcd_cmd(unsigned char n)
{
	lcd=n;
	Rs=0; //RegisterSelect=0 -->cmd_register
	En=1;
	lcd_delay(10);
	En=0;
}

void lcd_data(unsigned char dat)
{
	lcd=dat;
	Rs=1; //RegisterSelect=1-->Datareg
	En=1;
	lcd_delay(10);
	En=0;
}

void lcd_string(unsigned char str[])
{
	unsigned int i;
	for(i=0;str[i] !='\0';i++)
	{	lcd_data(str[i]);}
}
void lcd_delay(unsigned int time)
{
		int i,j;
		for(i=0;i<1000;i++)
		for(j=0;j<time;j++);
}
	